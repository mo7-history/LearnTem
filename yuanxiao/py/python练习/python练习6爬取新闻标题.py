from requests_html import HTMLSession

def get_news(): 
    ans_news_titles = [] 
    session = HTMLSession()
    r = session.get('https://news.baidu.com/')
    title1_baidu = r.html.find('#pane-news > div > ul > li.hdline0 > strong > a', first=True)
    ans_news_titles.append(title1_baidu)
    titles_baidu = r.html.find('#pane-news > ul:nth-child(n) > li.bold-item > a')
    ans_news_titles += titles_baidu
    for title in ans_news_titles:
        print(title.text)

if __name__=="__main__":
    get_news()
 
 