<?php include_once("top-part.php");

$emailError = '';
$nameError = '';
$addressError = '';
$telError = '';

if (isset($_POST["add"])) {
    $pumpId = $_POST["add"];
    if (isset($pumps[$pumpId])) {
        $_SESSION["cart"][$pumpId] = $pumps[$pumpId];
    }
}

if (isset($_POST["remove"])) {
    $pumpId = $_POST["remove"];
    if (isset($_SESSION["cart"][$pumpId])) {
        unset($_SESSION["cart"][$pumpId]);
    }
}

if (isset($_POST["checkout"])) {
    $name = trim($_POST["name"]);
    $email = trim($_POST["email"]);
    $address = trim($_POST["address"]);
    $telephone = trim($_POST["telephone"]);

    if (empty($_POST['name'])) {
        $nameError = "Please enter your name";
    }

    if (empty($_POST['address'])) {
        $addressError = "Please enter your address";
    }

    if (empty($_POST['tel'])) {
        $telError = "Please enter your telephone";
    }

    if (!empty($_POST['email'])) {
        if (!filter_var($_POST['email'], FILTER_VALIDATE_EMAIL)) {
            $emailError = 'Did you want to type ' . filter_var($_POST['email'], FILTER_SANITIZE_EMAIL) . '?';
        }
    } else if (empty($_POST['email'])) {
        $emailError = "Please enter your email";
    }

    $_SESSION["information"] =
        [
            "name" => $name,
            "email" => $email,
            "address" => $address,
            "telephone" => $telephone
        ];

    header("Location: receipt.php");
}

?>

<?php include("mid-part.php"); ?>
<div class='butt' onclick='window.scrollTo(0,0)'>
    <div id=div1>&uarr; Top</div>
</div>
<form method='post'>

    <?php foreach ($pumps as $pid => $pump) { ?>
        <?php echo "<div class='position'>";
        echo " <div class='pump' id='pid'><h3>{$pump['title']}</h3>";
        echo "{$pump['description']}" . "<br>";
        echo "{$pump['id']}" . "<br>";
        echo '$price:' . "{$pump['price']}"; ?>

        <?php if (isset($_SESSION["cart"][$pump['id']])) { ?>
            <button type='submit' name='remove' value=<?php echo "{$pump['id']}"; ?>>Remove from cart</button>
        <?php } else { ?>
            <button type='submit' name='add' value=<?php echo "{$pump['id']}"; ?>>Add to cart</button>
        <?php } ?>
        <?php echo "</div>";
        echo "<div class=textWrap>{$pump['image']}";
        echo "</div>";
        echo "</div>";
    } ?>


</form>
<section>
    <p class="two"><strong>Sorry, but I have no idea what that gas pump or soda machine that you have in the garage or
            that you're neighbor is trying to sell you is worth.<br>
            It's impossible for me to inspect, look at, visualize or otherwise peruse these pieces from thousands of
            miles away in order to give you an accurate<br> valuation.</strong><br>
        <small>Bob's Easy Payment Terms: 50% deposit buys the gas pump and begins the build (restoration). The balance
            is due when it's complete. Build time varies. Credit cards<br>
            preferred but we also take money orders, bank wire transfers and cash.
        </small>
        <br><br><strong>ALWAYS BUYING OLD GAS PUMPS AND SODA MACHINES</strong></p>

    <article>
        <form method="post">
            <fieldset>
                <legend>Personal details</legend>
                <label for='name'>Name</label><br/>
                <input name="name" placeholder="name"
                       id='name'/><?php echo "<span style = \"color:red\">" . $nameError . "</span><br>"; ?>
                <label for='email'>Email</label><br/>
                <input name="email" placeholder="email"
                       id='email'/><?php echo "<span style = \"color:red\">" . $emailError . "</span><br>"; ?>
                <label for='address'>Address</label><br/>
                <textarea name="address" placeholder="address" rows="4" cols="50"
                          id='address'></textarea><?php echo "<span style = \"color:red\">" . $addressError . "</span><br>"; ?>
            </fieldset>
            <fieldset>
                <legend>phone</legend>
                <label for='tel'>tel</label><br>
                <input name="telephone" value="" id="tel" placeholder="telephone" pattern="[+()0-9x ]{1,}"
                       title="please match the format requested" onblur="remove()"
                       oninput="map()"><?php echo "<span style = \"color:red\">" . $telError . "</span>"; ?>
                <span id='map'><img src="NANP.png" width=15 height=15></span><br>
            </fieldset>
            <fieldset>
                <legend>checkme</legend>

                <input type="checkbox" name="remember me" value="RM" id="rememberMe" onclick="storeIfo()"> Remember
                me<br>
                <input type="submit" name="checkout" value="check out"/>
            </fieldset>
        </form>
    </article>
</section>
<aside>
    <p class="two"><strong><a href="photo/cgp.html">Custom pump work </a>done on request.<br>
            Good selection of unrestored pumps available
            from $550 up. <br>Pump type limited to stock on hand. Call Bob for availability. <br>
            We also do gas pump and soda machine restoration estimates.</strong></p>
</aside>


<?php include_once("end-part.php"); ?>
        
        
        

