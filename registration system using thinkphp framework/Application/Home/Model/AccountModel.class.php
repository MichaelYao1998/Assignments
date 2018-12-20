<?php
/**
 * Created by PhpStorm.
 * User: Administrator
 * Date: 2018/12/20
 * Time: 10:38
 */
namespace Home\Model;
use Think\Model;

class AccountModel extends Model
{
    protected $connection = array(
        'DB_TYPE'   => 'mysqli', //数据库类型
        'DB_HOST'   => 'localhost', //服务器地址
        'DB_NAME'   => 'registration', //数据库名
        'DB_USER'   => 'root', //用户名
        'DB_PWD'    => 'root', //密码
        'DB_PORT'   => 3306, //端口
    );
}
?>