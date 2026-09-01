echo 'running c++ auto import because im lazy af'

for dir in */src/*/
do 
    dir=${dir%*/}      # remove the trailing "/"
    echo "${dir##*/}"    # print everything after the final "/"
done
