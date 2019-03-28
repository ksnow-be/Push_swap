to=$2
from=$1

ARG=`ruby -e "puts ($from..$to).to_a.shuffle.join(' ')"` ; ./push_swap $ARG | ./checker -v $ARG
rm -rf .*~
rm -rf *~
