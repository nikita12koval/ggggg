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
  Выполняя работу нам потребуется создать серверное и клиентское приложение на языке С++ с добавлением библиотек httplib.h и json.hpp



Далее напишем код серверного приложения на языке С++ и подключаем библиотеки httplib.h и json.hpp

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
	svr.listen("localhost", 1234);
}

Далее перешел на сайт  https://webhook.site и получил свой уникальный URL


```
<p align="center"> <img width="500" height="210" src="./pict/03.png"> </p>
<p align="center"> Рисинок 3 - HTML виджет </p> </br>


 Исходный код клиентского приложения:
```Python
from tkinter import *
from tkinter.font import BOLD
import requests
import json

def reload_data(event=None):
  try:
    response = requests.get('http://localhost:3000/raw').content.decode("utf8")
    cache = json.loads(response)  

    desc.config(text=str(cache["description"]))
    temp.config(text=str(cache["temp"]) + "C")  
  except requests.exceptions.ConnectionError:
    pass

root = Tk()  
root.title("Погода") 
root.pack_propagate()
root.bind("<Button-1>", reload_data)

top = Frame(root, bg="yellow")
top.pack(side=TOP, fill=X)     
middle = Frame(root, bg="white")
middle.pack(expand=True, fill=BOTH)
bottom = Frame(root, bg="yellow", width=200, height=50)
bottom.pack(side=BOTTOM, fill=X)


a = Label(top, font=("Times New Roman", 14), text="Симферополь", bg="yellow")
desc = Label(top, font=("Times New Roman", 14), bg="yellow")
temp = Label(middle, font=("Times New Roman", 48), bg="white")

a.pack(pady=0)
desc.pack(pady=0)
temp.pack(expand=True)

root.mainloop()  
```
<p align="center"> <img width="300" height="400" src="./pict/04.png"> </p>
<p align="center"> Рисунок 4 - Интерфейс клиенского приложения </p> </br>


**Вывод:**  В данной лабораторной работе яСоздал сервер на языке С++, обращающегося к openweathermap.com и возвращающий виджет или описание и температуру в формате json - Приложение с графическим интерфейсом, написанное на языке Python с использованием библиотеки Tkinter, получающее и обрабатывающее данные из сервера.