function remove() {
    var str = document.getElementById("tel").value;
    var res = str.replace(/[^0-9+x() ]/g, '');
    document.getElementById("tel").value = res;
}

function map() {
    var str = document.getElementById("tel").value;
    /*
        {3}: 3 or more
        {0,4}: between 0 and 4
        *: zero or more
        +: 1 or more
        ?: 0 or 1
        ^: start of a string
        $: end of a string
        ^ and &: the whole string
        [^0-9]: a string if no digits present
        \: use to match the literal version of meta character. e.g. \* means * itself
        /[a-z]/i: makes the search case sensitive
        /[a-z]/x: ignores whitespace inside the string
        /[a-z]/g: searches globally, ie.it does not stop at the first match
        /[a-z]/m: search on multiple lines
        /[a-z]/ixgm: does all 4
     */
    if (str.match(/^(\+[1])([ ]?\(?\d{3}\)?)[ ]?(\d{3})[ ]?(\d{4})[ ]?((x.\d{0,4})?|(\d{1,5})?)$/)) {
        document.getElementById("map").style.display = 'inline';
    } else {
        document.getElementById("map").style.display = 'none';
    }
}

function storeIfo() {
    if (document.getElementById("rememberMe").checked === true) {
        window.localStorage.name = document.getElementById('name').value;
        window.localStorage.email = document.getElementById('email').value;
        window.localStorage.address = document.getElementById('address').value;
        window.localStorage.tel = document.getElementById('tel').value;
    } else if (document.getElementById('rememberMe').checked !== true) {
        window.localStorage.clear();
    }
}

function prefilled() {
    document.getElementById('name').value = window.localStorage.getItem('name');
    document.getElementById('email').value = window.localStorage.getItem('email');
    document.getElementById('address').value = window.localStorage.getItem('address');
    document.getElementById('tel').value = window.localStorage.getItem('tel');
}

/*function change()
{
    if(document.getElementById("GP8002").value=="Add to cart")
    {
document.getElementById("GP8002").value="Remove from cart";
}
else if(document.getElementById("GP8002").value=="Remove from cart")
{
    document.getElementById("GP8002").value="Add to cart";
}
}*/
