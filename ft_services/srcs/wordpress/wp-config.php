<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 *
 * This file contains the following configurations:
 *
 * * MySQL settings
 * * Secret keys
 * * Database table prefix
 * * ABSPATH
 *
 * @link https://wordpress.org/support/article/editing-wp-config-php/
 *
 * @package WordPress
 */

// $_SERVER['HTTPS'] = 'on'; // http on?

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'admin' );

/** MySQL database password */
define( 'DB_PASSWORD', 'admin' );

/** MySQL hostname */
define( 'DB_HOST', 'mysql-service' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         '(4#G(EOb8LdN,DY!RQ#P;XH6-4m9Hy+Ge(qCh5`V0(-a$?BPP*<,;;Ow)@M;1C|B');
define('SECURE_AUTH_KEY',  'jQ|DpD4D8;p}A_iKE7 lJ6s);KX|mwu1wA+gxJgQ-|$52naMYj0h`5-+i!.7_C=m');
define('LOGGED_IN_KEY',    '^|9`KhO4N*R@>OO#F3k}i}bW0nd=C}+fJj,2[hdqVPu)_s9jnpbd WSr#<o+/0hr');
define('NONCE_KEY',        'v+tH+!G<j!*ej$,vL@]6U-cW`|j$2IP(yEs*Byq:6$$v<<XA;tNj7cqK/51#w^Y:');
define('AUTH_SALT',        'gY--N.*BmeF%+c,50R# vF!0kN[n7o}J#qt#~ANkJ| dr[--s4Ub3G&+P90EtYTi');
define('SECURE_AUTH_SALT', '0Z?HbP>oyKk_gpzn#%e~_x+P!9cY--qBy;JDy@|7|cg[eN(<cb{q:],J1.n)&{lY');
define('LOGGED_IN_SALT',   ';4|%qpN.i3+_ymo`v@evO<72a0W)ef#6,fO3f=()E2Yk[Of8f5#,O*oz2Z@. y3o');
define('NONCE_SALT',       'WBHU9|+2.y(S;|$&Uj_?!i6OesOvJyc4p5}eB@~6i@=9+|A#+Nkc|!}aD29MNy;p');

/**#@-*/

/**
 * WordPress Database Table prefix.
 *
 * You can have multiple installations in one database if you give each
 * a unique prefix. Only numbers, letters, and underscores please!
 */
$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 *
 * Change this to true to enable the display of notices during development.
 * It is strongly recommended that plugin and theme developers use WP_DEBUG
 * in their development environments.
 *
 * For information on other constants that can be used for debugging,
 * visit the documentation.
 *
 * @link https://wordpress.org/support/article/debugging-in-wordpress/
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';
