<?php if (!defined('THINK_PATH')) exit();?><!DOCTYPE html>
<html>
<head>
    <title> Register page</title>
    <link rel="stylesheet" type="text/css" href="/Public/CSS/style.css">
</head>
<body>
<div class="header">
    <h2>Register</h2>
</div>

<form method="post" action="register.html">
    <?php include('errors.php');?>
    <div class="input-group">
        <label>Username</label>
        <input type="text" name="username" value="<?php echo $username; ?>">
    </div>

    <div class="input-group">
        <label>Password</label>
        <input type="password" name="password">
    </div>

    <div class="input-group">
        <label>Confirm password</label>
        <input type="password" name="password_2">
    </div>

    <div class="input-group">
        <label>Email</label>
        <input type="email" name="email">
    </div>

    <div class="input-group">
        <button type="submit" class="btn" name="reg_user">Register</button>
    </div>
    <p>
        Already a member?<a href="login.html">Sign in</a>
    </p>
</form>
<p id="error">
    <?php echo ($error); ?>
</p>
</body>
</html>