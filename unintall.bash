#!/bin/sh
# Remove field, disable, uninstall

drush -y field-delete field_player
drush cron
drush cron
drush -y dis show
drush -y pm-uninstall show
