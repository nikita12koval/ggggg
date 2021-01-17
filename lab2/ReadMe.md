<p align="center">МИНИСТЕРСТВО НАУКИ  И ВЫСШЕГО ОБРАЗОВАНИЯ РОССИЙСКОЙ ФЕДЕРАЦИИ<br>
Федеральное государственное автономное образовательное учреждение высшего образования<br>
"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"<br>
ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ<br>
Кафедра компьютерной инженерии и моделирования</p>
<br>
<h3 align="center">Отчёт по лабораторной работе № 2<br> по дисциплине "Программирование"</h3>
<br><br>
<p>студента 1 курса группы ИВТ-б-о-202(2)<br>
Ковальчук Никита Сергеевич<br>
направления подготовки 09.03.01 "Информатика и вычислительная техника"</p>
<br><br>
<table>
<tr><td>Научный руководитель<br> старший преподаватель кафедры<br> компьютерной инженерии и моделирования</td>
<td>(оценка)</td>
<td>Чабанов В.В.</td>
</tr>
</table>
<br><br>
<p align="center">Симферополь, 2020</p>
<hr>

### Цель:

1. Получить представления о структуре post-запроса;
2. Изучить webhooks как метод взаимодействия web-приложений;


## Постановка задачи
1. Разработать и зарегистрировать навык для Алисы на сервисе ЯндексюДиалоги с помощью языков С++ и Python
2. В качестве backend-a для навыка реализуйте приложение на языке С++ выполняющее следующие функции:

1. Составление продуктовой корзины:

1. Добавление продукта в корзину;
2. Удаление продукта из корзины;
3. Очистка корзины;
4. Вывод списка товаров в корзине;
5. Подсчёт стоимости товаров в корзине.

2. Вывод справочной информации по навыку;
3. Регистрацию webhook-ов сторонних сервисов;
4.Отправку данных на сторонние сервисы. 

5. В качестве стороннего сервиса реализовать приложение на языке Python выполняющее следующие функции:

1. Ожидание данных о покупке;
2. Сохранение поступивших данных в excel-документ.


## Выполнение работы
  В данной работе потребуется создать серверное и клиентское приложение на языке С++ с добавлением библиотек httplib.h и json.hpp



Напишем код серверного приложения на языке С++ и подключим библиотеки httplib.h и json.hpp

Код C++ сервера:
```C++
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cpp_httplib/httplib.h>
#include <nlohmann/json.hpp>
using namespace httplib;
using json = nlohmann::json;

std::vector<std::string> webhooks;

std::string hello = u8R"(
    {
      "response": {
        "text": "Здравствуйте! Это мы, хороводоведы.",
        "tts": "Здравствуйте! Это мы, хоров+одо в+еды.",
        "buttons": [
            {
                "title": "Начать",
                "payload": {},
                "url": "https://webhook.site/db27d01b-e826-4282-b89a-ccc125950606",
                "hide": true
            }
        ],
        "end_session": false
      },
      "version": "1.0"
    })";

std::string str = u8R"(
	{
	  "response": {
		"text": "Хорошо",
		"tts": "Добавляю",
		"buttons": [
			{
				"title": "Добавить",
				"payload": {},
				"hide": true
			}
		],
		"end_session": false
	  },
	  "version": "1.0"
	})";
std::string str1 = u8R"(
	{
	  "response": {
		"text": "Какой товар добавить?",
		"tts": "Какой товар добавить?",
		"buttons": [
			{
				"title": "Носки",
                "price": 50
				"payload": {},
				"hide": true
			}
{
           "title": "Ботинки",
            "price": 1000
				"payload": {},
				"hide": true
}
		],
		"end_session": false
	  },
	  "version": "1.0"
	})";
void gen_response(const Request& req, Response& res) {
	json yandex = json::parse(req.body);

	if (yandex["session"]["new"])
	{
		res.set_content(hello, "text/json; charset=UTF-8");
	}
	else
	{
		if (yandex["request"]["nlu"]["tokens"][0] == u8"начать")
		{
			res.set_content(str, "text/json; charset=UTF-8");

		}

	}

}

std::string str2 = u8R"(
	{
	  "response": {
		"text": "1050 руб.",
		"tts": "1050 руб.",
		"buttons": [
			{
				"title": "хорошо",
				"payload": {},
				"hide": true
			}
		],
		"end_session": false
	  },
	  "version": "1.0"
	})";
void gen_response(const Request& req, Response& res) {
	json yandex = json::parse(req.body);

	if (yandex["session"]["new"])
	{
		res.set_content(str1, "text/json; charset=UTF-8");
	}
	else
	{


	}

}



void findAndRepl(std::string& data, std::string toSearch, std::string replStr) {
	size_t pos = data.find(toSearch);
	while (pos != std::string::npos) {
		data.replace(pos, toSearch.size(), replStr);
		pos = data.find(toSearch, pos + replStr.size());
	}
}


void check_conf() {
	std::string webhooks_file_name = "webhook.json";
	std::ifstream webhooks_file(webhooks_file_name);
	std::cout << "открываю файл\n";
	if (webhooks_file.is_open())
	{
		int i = 0;
		std::cout << "Готово!\n";
		json j = json::parse(webhooks_file);

		for (int i = 0; i < j["webhooks"].size(); i++) {
			webhooks.push_back(j["webhooks"][i]);
		}
	}
	else
	{
		std::cout << "Ошибка создание нового\n";
		std::ofstream webhooks_file(webhooks_file_name);
		std::string config = R"(
			{
			"webhooks":[]
			})";
		webhooks_file << config;
		webhooks_file.close();
		webhooks.clear();
	}
}




void gen_response_webhooks(const Request& req, Response& res) {

	std::string template_file_name = "Web_temp1.html";
	std::ifstream template_file(template_file_name);
	std::string template_str;

	if (template_file.is_open())
	{
		getline(template_file, template_str, '\0');
		template_file.close();
	}
	else
	{
		std::cout << "Ошибка открытия template.html";
	}

	if (webhooks.empty()) {
		findAndRepl(template_str, "{webhooks_list}", "");
	}
	else {
		std::string template_file_name = "Processing_block.html";
		std::ifstream template_file_block(template_file_name);
		std::string template_block;
		std::string temp;

		for (int i = 0; i < webhooks.size(); i++) {
			if (template_file_block.is_open())
			{
				getline(template_file_block, template_block, '\0');
				temp = template_block;
			}
			else {
				std::cout << "ошибка открытияe template_block.html";
				break;
			}
			findAndRepl(temp, "{Webhook URL}", webhooks[i]);

			findAndRepl(template_str, "{webhooks_list}", temp);
		}
		template_file_block.close();
		findAndRepl(template_str, "{webhooks_list}", "");
	}
	res.set_content(template_str, "text/html");

}


void gen_response_webhooks_post(const Request& req, Response& res) {
	std::string webhooks_file_name = "webhook.json";
	std::ifstream webhooks_file(webhooks_file_name);
	json j;

	if (webhooks_file.is_open())
	{
		webhooks_file >> j;
		webhooks_file.close();

		if (req.has_param("del")) {
			auto val = req.get_param_value("del");
			webhooks.erase(std::remove(webhooks.begin(), webhooks.end(), val), webhooks.end());
		}
		else if (req.has_param("set")) {
			auto val = req.get_param_value("set");
			webhooks.push_back(val);
		}
		else {
			std::cout << "Ошибка запроса";
		}
		json j2;
		j2["webhooks"] = webhooks;
		std::ofstream conf_file(webhooks_file_name);
		conf_file << j2;
		conf_file.close();
	}
	else
	{
		std::cout << "Не могу открыть файл";
	}
	gen_response_webhooks(req, res);
}

int main() {
	Server svr;
	check_conf();

	svr.Post("/", gen_response);
	svr.Get("/webhooks", gen_response_webhooks);
	svr.Post("/webhooks", gen_response_webhooks_post);
	std::cout << "Start server... OK\n";
	svr.listen("localhost", 1234)
}

Далее перейдем на сайт  https://webhook.site и получил свой уникальный URL(Рис.1)

```
<p align="center"> <img width="900" height="400" src="./pict/26.png"> </p>
<p align="center"> Рисинок 1 -  https://webhook.site </p> </br>


Далее создаем  консольное приложение С++,и подключаем библиотеку cpp_httplib и вставил свой URL


#include <iostream>
#include <cpp_httplib/httplib.h>
using namespace httplib;

int main() {
    // Создаём клиент и привязываем к домену. Туда пойдут наши запросы
    Client cli("http://webhook.site");
    // Отправляем post в теле которого будет текст {"Hello": "world"}
    auto res = cli.Post("/db27d01b-e826-4282-b89a-ccc125950606", R"({"Hello": "world"})", "text/json");
    // res преобразуется в true, если запрос-ответ прошли без ошибок
    if (res) {
        // Проверяем статус ответа, т.к. может быть 404 и другие
        if (res->status == 200) {
            // В res->body лежит string с ответом сервера
            std::cout << res->body << std::endl;
        }
        else {
            std::cout << "Status code: " << res->status << std::endl;
        }
    }
    else {
        auto err = res.error();
        std::cout << "Error code: " << err << std::endl;
    }
}

Запускаем gnork и получаем URL(Рис.2)

```
<p align="center"> <img width="900" height="400" src="./pict/24.png"> </p>
<p align="center"> Рисинок 1 -  gnork </p> </br>

Создаем диалог на Яндекс.Диалоги(Рис.3)

```
<p align="center"> <img width="900" height="400" src="./pict/25.png"> </p>
<p align="center"> Рисинок 1 -  Яндекс.Диалоги </p> </br>


 Исходный код клиентского приложения:
```Python
from flask import Flask, request
import json
import openpyxl

app = Flask(__name__)

def reload_data():
    answer = requests.get('http://localhost:5000/raw').content.decode("utf8")
    if answer:
        info = json.loads(answer)
    else:
        print('Error')

@app.route('/', methods=['POST', 'GET'])
def index():
    if request.method == 'POST':
        return "Это POST запрос"
    if request.method == 'GET':
        return "Это GET запрос"
 
if __name__ == "__main__":
    app.run()

    with open ('webhook.json') as file:
        data = json.load(file)
        for webhook in data ['webhook']:
            ID = webhook['ID']
            UserID = webhook['User ID']
            Datetime = webhook['Datetime']
            Item = webhook['Item']
            Price = webhook['Price']
    print (data['webhook reciecve'])
book = openyxl.Workbook()
sheet = book.active
sheet['A2'] = 'ID'
sheet['B2'] = 'User ID'
sheet['C2'] = 'Datetime'
sheet['D2'] = 'Item'
sheet['E2'] = 'Price'

row = 2 
for movie in data['webhook']:
    sheet[row][0] = webhook['ID']
    sheet[row][1] = webhook['User ID']
    sheet[row][2] = webhook['Datetime']
    sheet[row][3] = webhook['Item']
    sheet[row][4] = webhook['Price']
    row += 1

book.save("list.xlsx")
book.close()
=======
from flask import Flask, request
 
app = Flask(__name__)
 
@app.route('/', methods=['POST', 'GET'])
def index():
    if request.method == 'POST':
        return "Это POST запрос"
    if request.method == 'GET':
        return "Это GET запрос"
 
if __name__ == "__main__":
    app.run()
>>>>>>> db27d01b-e826-4282-b89a-ccc125950606
=======
from flask import Flask, request
 
app = Flask(__name__)
 
@app.route('/', methods=['POST', 'GET'])
def index():
    if request.method == 'POST':
        return "Это POST запрос"
    if request.method == 'GET':
        return "Это GET запрос"
 
if __name__ == "__main__":
    app.run()
>>>>>>> db27d01b-e826-4282-b89a-ccc125950606


**Вывод:**  В данной лабораторной работе я разработал и зарегистрировал навык для Алисы на сервисе ЯндексюДиалоги.Реализовал приложение на языке С++.Создал клинтское приложение на языке С++.Получил опыт разработки клиент-серверного приложения.