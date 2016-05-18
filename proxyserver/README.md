代理服务器相关配置和接口
========================
---
##服务端环境
* 1.代理服务器Squid
* 2.其它环境Mysql+PHP

##接口配置
telanx/config/config.php配置:

    <?php
        // 配置数据库，访问白名单
    $db_config = array(
        'host'=>'localhost',
            'user'=>'root',
                'pwd'=>'toor'
                    
            );

                // 此处配置访问插件服务器白名单列表
                    // ::1和127.0.0.1必须放入到本地列表中
                        $whiteList = array('::1','127.0.0.1');

                        ###squid配置
                        * 1.myvpn.c用户认证的
                        * 2.squid配置文件，基本不用改

                        ###设置定时任务清理日志

                        推荐使用国外的VPS供应商linode(非广告)
