
/*minimum insertions and deletions to make str1 equal to str2
approach:- find lenght of lcsubseq in both strings
to make str1-> lcs, we need to delete, so number of delete operations = (str1.len)-(lcs.len)
to make lcs->str2 we need to insert, so number of insertions= str2.len-lcs.len
//!total operations= str1.len+str2.len-2*lcs.len 
*/

