#!/bin/bash
MAILTO=blaze@blaze.pl
DATE=`date +%Y%m%d-%H%M`
HOSTNAME=`hostname`
FILENAME="/www/backup/${HOSTNAME}_${DATE}.7z"
PATH="/usr/local/bin:/bin:/usr/bin:/usr/local/sbin:/usr/sbin"
SECUREPASS="random"
source /etc/profile
/usr/lib/oracle/18.5/client64/bin/sqlplus web/$SECUREPASS@db202001232013_high @/www/desc.sql > /www/log
`which chmod` -R 700 /www >> /www/log
`which 7za` a -t7z -m0=lzma -mx=9 -mfb=64 -md=32m -ms=on -p$SECUREPASS -mhe=on ${FILENAME} /www -xr!backup >> /www/log
/www/dropbox/dropbox_uploader.sh upload ${FILENAME} ${HOSTNAME}_${DATE}.7z >> /www/log
`which cat` /www/log | `which mailx` -vvv -s "NEW Backup from $HOSTNAME as of $DATE" $MAILTO >> /www/log
