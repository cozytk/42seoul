import requests

URL = 'http://127.0.0.1:8081'
headers = {'Host': '127.0.0.1:8081', 'User-Agent': 'python-post-test', 'Content-Type': 'test/file'}

response = requests.post(URL, headers=headers)

print (response.status_code)
print (response.text)
