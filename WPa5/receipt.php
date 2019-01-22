<?php
include("top-part.php");
$information = $_SESSION["information"];
$cart = $_SESSION["cart"];

$items = fopen("orders.tsv", "a");
$product[] = $information["name"];
$product[] = $information["email"];
$product[] = $information["address"];
$product[] = $information["telephone"];

foreach ($cart as $key => $pump) {
    $product[] = $pump["id"];
    $product[] = $pump["price"];
}

fputcsv($items, $product, "\t");


fclose($items);
unset($_SESSION["information"]);
unset($_SESSION["cart"]);
?>


<?php $total = 0.00; ?>

    <title>Receipt</title>
    <img src="photo/group.png" align="middle" height="300" width="400"/>
    <p class=four>contact : 4140 JVL Industrial Park Dr. #102, Marietta, GA 30066 (Just off I-575)
        678-494-2996 M-F 10 - 4 Sat by appointment Bob@Bobs-Garage.com</p>
    <h4>Name</h4>
<?php echo $information['name']; ?>
    <h4>Email</h4>
<?php echo $information['email']; ?>
    <h4>Address</h4>
<?php echo $information['address']; ?>
    <h4>Telephone</h4>
<?php echo $information['telephone']; ?>
    <h4>order</h4>
<?php foreach ($cart as $key => $pump) {
    $total += $pump['price'];
    echo "{$pump['id']}" . "<br>";
    echo "{$pump['title']}" . "<br>";
    echo 'price:' . "{$pump['price']}" . "<br>";;

} ?>
    <h4>Total</h4>
    $<?php
echo number_format((float)$total, 2, '.', ''); ?>
<?php include("end-part.php"); ?>