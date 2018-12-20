<?php if (!defined('THINK_PATH')) exit();?><!DOCTYPE html>
<html>
<head>
    <title>Login page</title>
    <link rel="stylesheet" type="text/css" href="/Public/CSS/style.css"/>
</head>
<body>
<div class="header">
    <h2>Login</h2>
</div>

<form method="post" action="login.html">
    <?php include('errors.php'); ?>
    <div class="input-group">
        <label>Username</label>
        <input type="text" name="userInfo" placeholder="Username or email address">
    </div>

    <div class="input-group">
        <label>Password</label>
        <input type="password" name="password">
    </div>

    <div class="input-group">
        <button type="submit" class="btn" name="login_user">Login</button>
    </div>
    <p>
        Not yet a member? <a href="register.html">Sign up</a>
    </p>
</form>
<p id="error">
    <?php echo ($errMessage); ?>
</p>
</body>
</html>