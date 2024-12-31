#!/usr/bin/python3

import requests
from bs4 import BeautifulSoup

# spécifiez l'URL de la page à récupérer
url = 'http://pentest-isima.fr/Epreuves_Web/epreuve4/index.php'
filename = "res3.txt"

# envoyez une requête GET à l'URL
response = requests.get(url)

# créez un objet BeautifulSoup à partir du contenu HTML de la réponse
soup = BeautifulSoup(response.content, 'html.parser')

# trouvez tous les liens sur la page en utilisant la balise "a"
links = soup.find_all('a')

# itérez sur les liens et affichez l'URL
for link in links:

    lien = str(link.get('href'))
    if 'http' in lien:
        print(lien)

# traiter = set()
# a_traiter = {"http://hacknowledge-contest.org/"}
# i = 0
# while len(a_traiter) != 0:
#     lien = a_traiter.pop()
#     traiter.add(lien)

#     # on regarde la nouvelle page
#     response = requests.get(lien)
#     soup = BeautifulSoup(response.content, 'html.parser')
#     links = soup.find_all('a')

#     for link in links:
#         url = str(link.get('href'))
#         if 'http' == url[0:4] and not (url in traiter):
#             a_traiter.add(url)
#     i += 1
#     if i ==200:
#         break
#     print(i)

i = 0
f = open(filename, "w")

while i < 200:
    i += 1
    url = "http://pentest-isima.fr/Epreuves_Web/epreuve4/index.php?page="+ str(i)
     # on regarde la nouvelle page
    response = requests.get(url)
    soup = BeautifulSoup(response.content, 'html.parser')
    div = soup.find_all("div", class_="post")
    f.write(f"page n°{i}\n" + str(div) + "\n")


# with open("res.txt", "w") as f:
#     for link in traiter:
#         f.write(link + "\n")
