#!/bin/sh


cd /var/www/html
curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar
sleep 5
./wp-cli.phar core download --allow-root
./wp-cli.phar config create --dbname=$WORDPRESS_DB_NAME --dbuser=$WORDPRESS_DB_USER --dbpass=$WORDPRESS_DB_PASSWORD --dbhost=$WORDPRESS_DB_HOST --allow-root
./wp-cli.phar core install --url=$WP_DOMAIN --title=$WORDPRESS_TITLE --admin_user=$WORDPRESS_ADMIN_USER --admin_password=$WORDPRESS_ADMIN_PASSWORD --admin_email=$WORDPRESS_ADMIN_EMAIL --allow-root
./wp-cli.phar user create $WP_GUEST_USER $WP_GUEST_EMAIL --role=subscriber --user_pass=$WP_GUEST_PASSWORD --allow-root
php-fpm8.2 -F