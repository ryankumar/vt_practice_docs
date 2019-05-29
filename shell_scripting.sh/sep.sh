IN="bla@some.com;john@home.com"

OIFS=$IFS
IFS=';'
mails2=$IN
for x in $mails2
do
    echo "> [$x]"
done

IFS=$OIFS
