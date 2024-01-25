from requests_html import HTMLSession

def get_news(): 
    ans_news_titles = [] 
    session = HTMLSession()
    r2 = session.get('https://news.163.com/')
    title1_163 = r2.html.find('#js_top_news > h2:nth-child(1) > a', first=True)
    title2_163 = r2.html.find('#js_top_news > h2.top_news_title > a', first=True)
    titles_163 = r2.html.find('#js_top_news > ul:nth-child(n) > li:nth-child(n)')
    ans_news_titles.append(title1_163)
    ans_news_titles.append(title2_163)
    ans_news_titles += titles_163
    for title in ans_news_titles:
        print(title.text)

if __name__=="__main__":
    get_news()