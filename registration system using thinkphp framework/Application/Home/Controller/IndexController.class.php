<?php

namespace Home\Controller;

use Think\Controller;
use Think\Exception;

class IndexController extends Controller
{
    public function login()
    {
        /*
           相对应的网址，register.local/index.php/Home/index/login
           M 实例化对象
        */
        if (isset($_POST['login_user'])) {
            $userAccount = D('Account')->where(['userInfo' => D('Account')->username])->find();
            $accountInfo = I('post.userInfo');
            $username=D('Account')->username;
            $password = md5(I('post.password'));
            $pwd = D('Account')->password;
            $email = D('Account')->email;
//            $userAccount = D('Account')->getField('username', true);
//            $passwordArr=explode(" ",$password);
//             $pwd = D('Account')->getField('password');
//            $pwdStr = implode(" ", $pwd);
//            $email = D('Account')->getField('email', true);
//            $pwdE = D('Account')->getField('email,password');
//            $userAccount=array(
//                'userInfo' =>  D('Account')->username
//            );
            var_dump($password);
            var_dump($pwd);
            try {
                if ($accountInfo == $username || $accountInfo == $email) {
                    if ($password == $pwd) {
                        $this->success('redirect successful', 'test');
                    } else {
                        throw new Exception('password does not match');
                    }
                } else {
                    throw new Exception('User does not exist');
                }
            } catch
            (Exception $e) {
                $this->assign('errMessage', $e->getMessage());
            }
        }
        $this->display();
    }

    public function register()
    {
        if (isset($_POST['reg_user'])) {
            $userModel = D('Account');
            $userModel->create();//创建users数据对象
            $userName = $userModel->username;
            $user = $userModel->where(['username' => $userName])->find();
            $pwd2 = I('post.password_2');
            // var_dump($user);
            try {
                if (empty($user)) {
                    if ($pwd2 != $userModel->password) {
                        throw new Exception('Password does not match');
                    } else {
                          $userModel->password = md5($userModel->password);
                    }
                    $uid = $userModel->add();//->add把数据对象添加到数据库
                    if (!empty($uid)) {
                        //网页跳转
                        //$this->redirect('test', [], 2, 'redirect successful');
                        $this->success('redirect successful', 'test');
                    } else {
                        throw new Exception('redirect failure');
                    }
                } else {
                    throw new Exception('User already existed');
                }
            } catch (Exception $e) {
                $this->assign('error', $e->getMessage());
            }
        }
        $this->display();
    }

    public
    function test()
    {
        $this->display();
    }
}

?>