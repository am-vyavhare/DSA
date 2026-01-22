string gameOfStones(int num){
    /*for only 3 stones the 2nd person Bob will win other wise for every even 
    Ale will take all stone and win and for every odd except 3 Ale will 
    remove even stones from it such that 3 remains means opponent can
    only take 1 or 2 and Ale definately get at least 1 stone to pick and win
    */
    if(num == 3){
        return "Bob";
    }
    return "Ale";
}