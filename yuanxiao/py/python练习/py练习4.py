from requests_html import HTMLSession

session = HTMLSession()

firstPage = session.get('https://sou.zhaopin.com/?jl=530&kw=python&kt=3')
firstPage.html.render()
print(firstPage.html.text)