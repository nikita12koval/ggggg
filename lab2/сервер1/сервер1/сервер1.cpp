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

		],
		"end_session": false
	 },
	  "version": "1.0"
	})";
std::string basket = u8R"(
	{
	  "response": {
		"text": "Performing basket mode",
		"tts": "Performing basket mode",
		"buttons": [
			{
				"title": "Предпринимаю очищение корзины",
				"payload": {},
				"hide": true
			}
		],
		"end_session": false
	  },
	  "version": "1.0"
	})";
std::string clebask = u8R"(
	{
	  "response": {
		"text": "Корзина. Поможет организовать покупки",
		"tts": "Корзина. Поможет организовать покупки",
		"buttons": [
			{
				"title": "добавить товар",
				"payload": {},
				"hide": true
			}
		],
		"end_session": false
	  },
	  "version": "1.0"
	})";
std::string add = u8R"(
	{
	  "response": {
		"text": "Каталог товаров",
		"tts": "Каталог товаров",
		"buttons1": [
			{
				"title": "Носки",
				"payload": {},
				"hide": true
			}
		],
		"end_session": false
      "buttons2": [
			{
				"title": "Ботинки",
				"payload": {},
				"hide": true
			}
		],
		"end_session": false
      "buttons3": [
			{
				"title": "Штаны",
				"payload": {},
				"hide": true
			}
		],
		"end_session": false
	  },
	  "version": "1.0"
	})";
std::string adquant = u8R"(
	{
	  "response": {
		"text": "Количество",
		"tts": "Количество",
		"buttons": [
			{
				"title": "5 шт",
				"payload": {},
				"hide": true
			}
		],
		"end_session": false
	  },
	  "version": "1.0"
	})";
std::string remquest = u8R"(
	{
	  "response": {
		"text": "Какой товар удалить?",
		"tts": "Какой товар удалить?",
		"buttons": [
			"buttons1": [
			{
				"title": "Да",
				"payload": {},
				"hide": true
			}
		],
		"end_session": false
      "buttons2": [
			{
				"title": "Нет",
				"payload": {},
				"hide": true
			}
		],
		"end_session": false
	  },
	  "version": "1.0"
	})";
std::string а = u8R"(
	{
	  "response": {
		"text": "Количество?",
		"tts": "Количество?",
		"buttons": [
			{
				"title": "5 штук",
				"payload": {},
				"hide": true
			}
		],
		"end_session": false
	  },
	  "version": "1.0"
	})";
std::string none = u8R"(
	{
	  "response": {
		"text": "Функция неверная",
		"tts": "Функция неверная",
		"buttons": [
			{
				"title": "Повторить?",
				"payload": {},
				"hide": true
			}
		],
		"end_session": false
	  },
	  "version": "1.0"
	})";
std::string norest = u8R"(
	{
	  "response": {
		"text": "Очистка корзины",
		"tts": "Очистка корзины",
		"buttons": [
			{
				"title": "Повтор запуска корзины",
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
	else if (yandex["request"]["nlu"]["tokens"][0] == u8"говорить")
	{
		res.set_content(str, "text/json; charset=UTF-8");

	}
	else if (yandex["request"]["nlu"]["tokens"][0] == u8"добавить")
	{
		res.set_content(str1, "text/json; charset=UTF-8");

	}
	else if (yandex["request"]["nlu"]["tokens"][0] == u8"что добавить")
	{
		res.set_content(str2, "text/json; charset=UTF-8");

	}
	else if (yandex["request"]["nlu"]["tokens"][0] == u8"Запрашиваю режим корзины")
	{
		res.set_content(basket, "text/json; charset=UTF-8");
	}
	else if (yandex["request"]["nlu"]["tokens"][0] == u8"")
	{
		res.set_content(none, "text/json; charset=UTF-8");
	}
	else if (yandex["request"]["nlu"]["tokens"][0] == u8"Я поропробую еще")
	{
		res.set_content(norest, "text/json; charset=UTF-8");
	}
	else if (yandex["request"]["nlu"]["tokens"][0] == u8"Запрашиваю повтор запуска режима корзины")
	{
		res.set_content(str2, "text/json; charset=UTF-8");
	}
	else if (yandex["request"]["nlu"]["tokens"][0] == u8"Performing basket mode")
	{
		res.set_content(basket, "text/json; charset=UTF-8");
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
	std::cout << "Открытие файла\n";
	if (webhooks_file.is_open())
	{
		int i = 0;
		std::cout << "Открыто!\n";
		json j = json::parse(webhooks_file);

		for (int i = 0; i < j["webhooks"].size(); i++) {
			webhooks.push_back(j["webhooks"][i]);
		}
	}
	else
	{
		std::cout << "Ошибка.Создание нового\n";
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
		std::string template_file_name = "_block.html";
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
				std::cout << "Ошибка открытия template_block.html";
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
		std::cout << "Ошибка открытия файла";
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