
read -p "helo whats yo nam : " name 
echo -e "hello $name\nwellcome to $0 \n you have passed $# arguments those are:\n"
echo -e "by for loop:\n"
 

echo "By for loop:"
for arg in "$@"; do
    echo "#$arg"
done

echo "By while loop:"
i=1
for arg in "$@"; do
    echo "#$arg"
    ((i++))
done

# chat = `ls`
# echo "you are - $chat"


lst=`ls`
echo -e "listed = $lst \n"
charter =$(ls | grep "delete_the_rep")
echo "$charter"

# charter=$(ls | grep "delete_the_rep")
# echo "$charter"
