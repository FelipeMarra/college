CHACHE_SIZE = 8

dataToRead = [3, 7, 2, 3, 11, 15, 5, 4, 4, 2, 8, 32, 16, 2, 21, 21, 21,2, 4, 8, 16, 32, 24, 21]

def dictMapping():
    cache = [None] * CHACHE_SIZE
    erros = 0
    for data in dataToRead:
        position = data % CHACHE_SIZE
        if(cache[position] != data):
            erros = erros + 1
            print("Error to insert data: ", data, "in position: ", position, "previous was ", cache[position])
        cache[position] = data
    print("Cache ", cache)
    print("ERROS ", erros)

def totalAssociativity():
    postitions = [5, 0, 2, 0, 1, 6, 5, 2, 7, 0, 3, 3, 5, 6, 1, 3, 3, 5, 5, 5, 2, 5, 5, 1]
    cache = [None] * CHACHE_SIZE
    erros = 0
    for i in range(len(dataToRead)):
        data = dataToRead[i]
        position = postitions[i]
        if(not data in cache):
            erros = erros + 1
            print("Error to insert data: ", data, "in position: ", position, "previous was ", cache[position])
        cache[position] = data
    print("Cache ", cache)
    print("ERROS ", erros)

def cache_n_blocks():
    cache = [None] * CHACHE_SIZE
    erros = 0
    n_blocks = 4
    block_range = int(CHACHE_SIZE / n_blocks)
    #blockCount is the last position where some data wasstored into the block
    blockCount = [0] * n_blocks

    for data in dataToRead:
        block = data % n_blocks
        startPosition = block_range * block
        finalPosition = startPosition +  block_range

        #look for data in block
        blockContainsData = False
        for j in range(startPosition, finalPosition):
            if(cache[j] == data):
                blockContainsData = True
                break
        
        if(not blockContainsData):
            #count error
            erros = erros + 1
            #put data in position
            position = blockCount[block] + block * block_range
            print("Error to read data: ",data,"in block: ",block+1, "in position ", blockCount[block])
            cache[position] = data
            blockCount[block] = (blockCount[block] + 1) % block_range

    print("Cache ", cache)
    print("ERROS ", erros)