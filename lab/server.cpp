#include <cpp_httplib/httplib.h>
#include <nlohmann/json.hpp>
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace httplib;
using json = nlohmann::json;

json new_json;
json json_cache;
json _json_time;
int timen = 0;
int cache = 0;
int temp = 0;
int new_q = 0;

void response(const Request& req, Response& rez) {
		
		std::string str;
		std::ifstream html("HTMLWid.html");
		
		Client Cli("http://worldtimeapi.org");
		auto rezult = Cli.Get("/api/timezone/Europe/Simferopol");
		if (rezult) {			
			if (rezult->status == 200) {		
				_json_time = json::parse(rezult->body);			 
				timen = _json_time["unixtime"].get<int>();					
			}																				
			else {							
				std::cout << "Status code: " << rezult->status << std::endl;			
			}
		}
		else 
		{
			auto Error = rezult.error();  
			std::cout << "Error code: " << Error << std::endl;
		}
		
		
		Client cli("http://api.openweathermap.org"); 
		auto rezult2 = cli.Get("/data/2.5/onecall?lat=44.952116&lon=34.102411&lang=ru&units=metric&appid=0083423f4d6d9885477d9ae0b151ab8f");
	
		
		if (rezult2) {
		
			if (rezult2->status == 200) {
				json_cache = json::parse(rezult2->body);
				cache = json_cache["hourly"][json_cache["hourly"].size() - 1]["dt"].get<int>(); 
			
				for (int i = json_cache["hourly"].size(); i > 0; --i) {	
					for (int q = 0; q < json_cache["hourly"].size(); q++) {
						if (cache > timen and json_cache["hourly"][q]["dt"] <= cache) {   
							temp = json_cache["hourly"][q]["dt"];					
							cache = temp;
							new_q = q;
						}
					}

				}

			}
			else {
				std::cout << "Status code: " << rezult2->status << std::endl; 
			}
		}
		else { 
			auto Error = rezult2.error();
			std::cout << "Error code: " << Error << std::endl;
		}

		new_json["description"] = json_cache["hourly"][new_q]["weather"][0]["description"];
		new_json["temp"] = std::to_string(json_cache["hourly"][new_q]["temp"].get<int>());
		std::getline(html, str, '\0');
		
		while (str.find("{hourly[i].temp}") != std::string::npos) 
			
			
			str.replace(str.find("{hourly[i].temp}"), 16,
				std::to_string(json_cache["hourly"][new_q]["temp"].get<int>()));
		str.replace(str.find("{hourly[i].weather[0].description}"), 34, 
			json_cache["hourly"][new_q]["weather"][0]["description"]);
		str.replace(str.find("{hourly[i].weather[0].icon}"), 27, 
			json_cache["hourly"][new_q]["weather"][0]["icon"]);
		
		rez.set_content(str, "text/html");
		}

void response_raw(const Request& req, Response& rez) {
	Client("http://localhost:3000").Get("/");
	rez.set_content(new_json.dump(4), "text/json");  
}

int main() {
	Server NKoval;
	NKoval.Get("/raw", response_raw); 
	NKoval.Get("/", response); 
	std::cout << "OK\n";  
	NKoval.listen("localhost", 3000); 
}















