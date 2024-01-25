from requests_html import HTMLSession
session = HTMLSession()
r = session.get('http://stock.finance.sina.com.cn/usstock/quotes/aapl.html')
r.html.render()
title=r.html.find('#hqPrice',first=True)
print(title.text)

