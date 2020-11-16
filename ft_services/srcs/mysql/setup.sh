#!/bin/sh
/usr/bin/telegraf &
/usr/bin/mysql_install_db --user=root
/usr/bin/mysqld --user=root --bootstrap --verbose=0 < /mysql-init
/usr/bin/mysqld --user=root --console
