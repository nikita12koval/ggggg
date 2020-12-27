from tkinter import *
from tkinter.font import BOLD
import requests
import json

def reload_data(event=None):
	try:
		response = requests.get('http://localhost:3000/raw').content.decode("utf8") #запрашиваем ответ у http://localhost:3000/raw и декодим в utf8
		cache = json.loads(response)  

		desc.config(text=str(cache["description"])) #config исползуем для изменения текста и дригие параметры кнопки 
		temp.config(text=str(cache["temp"]) + "C") #config исползуем для изменения текста и дригие параметры кнопки 
	except requests.exceptions.ConnectionError:
		pass

root = Tk() #создаем окно 
root.title("Погода") #оглавление окна с названием Погода
root.pack_propagate() #
root.bind("<Button-1>", reload_data) #при нажатие на левую кнопку мышки обновляем данный о погоде

top = Frame(root, bg="yellow") #создаем область для верхней части окна
top.pack(side=TOP, fill=X)     #задаем положение 
middle = Frame(root, bg="white")#создаем область для верхней части окна
middle.pack(expand=True, fill=BOTH)#задаем положение
bottom = Frame(root, bg="yellow", width=200, height=50)#создаем область для нижней части окна
bottom.pack(side=BOTTOM, fill=X)#задаем положение


a = Label(top, font=("Times New Roman", 14), text="Симферополь", bg="yellow") #создаем надпись и задаем ему размер,шрифт и цвет под ним
desc = Label(top, font=("Times New Roman", 14), bg="yellow") #задаем шрифт размер и цвет под надписью погоды
temp = Label(middle, font=("Times New Roman", 48), bg="white") #задаем шрифт размер и цвет под надписью температуры

a.pack(pady=0)  #pack менеджер геометрии,который размещает виджеты
desc.pack(pady=0)
temp.pack(expand=True)


root.mainloop()#получает информацию о событиях и отправляет на виджеты  