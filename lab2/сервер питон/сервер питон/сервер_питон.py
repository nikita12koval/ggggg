from flask import Flask, request
import json
import openpyxl

app = Flask(__name__)

def reload_data():
    answer = requests.get('http://localhost:5000').content.decode("utf8")
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
    >>>>>>> db27d01b-e826-4282-b89a-ccc125950606

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



