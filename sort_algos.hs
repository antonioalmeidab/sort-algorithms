-- insertion sort
putInt :: Int -> [Int] -> [Int]
putInt a [] = [a]
putInt a (x:xs) | a > x = x : putInt a xs
                | otherwise = [a] ++ [x] ++ xs

insertionSortTail :: [Int] -> [Int] -> [Int]
insertionSortTail [] acc = acc
insertionSortTail (x:xs) acc = insertionSortTail xs $ putInt x acc

insertionSort :: [Int] -> [Int]
insertionSort ls = insertionSortTail ls []

-- selection sort 
putIndex ls = zip ls [1..]

selectionSort [] = []
selectionSort ls = mini : (selectionSort restOfList) 
                    where lsIndexed = putIndex ls
                          mini = fst (minimum lsIndexed)
                          restOfList = fst (unzip (filter (/= minimum lsIndexed) (lsIndexed)))


-- bubble sort
