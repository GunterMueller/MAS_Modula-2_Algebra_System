#

#set -x


cd $1
for  x in *
do
#echo $x
if [ ! -d $x ]; then
 echo $x
  ln -s $x ../$2/$x
fi
if [ -d $x ]; then
 echo $x
 mkdir ../$2/$x
 cd $x
 for y in *
 do
   if [ ! -d $y ]; then
    echo $y
    ln -s $y ../../$2/$x/$y
   fi
 done

 cd ..
 
fi
done

