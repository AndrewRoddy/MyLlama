# Llama cpp runner

## Steps to build repository
#### Clone llama.cpp directory in source folder
```
git clone https://github.com/ggml-org/llama.cpp
```

#### Make sure you directory looks like this
```
|-- llama.cpp
|-- myllama
|   |-- myLlama.cpp
|   |-- output.txt
|   README.md
```

#### Run CMake in the llama.cpp directory
Switch to the proper directory. 
```
cd llama.cpp
```
Then run CMake
```
cmake -B build
```

#### Download the gguf to run the model in the models folder
Go into the models folder
```
cd models
```
Instantly download the model into the folder
```
curl.exe -L -o llama-2-7b-chat.Q2_K.gguf https://huggingface.co/TheBloke/Llama-2-7B-Chat-GGUF/resolve/main/llama-2-7b-chat.Q2_K.gguf
```
#### Go back into the myllama folder



1. Put llama.cpp into a folder next to this
    - Download from 
    [Download Website](https://github.com/ggerganov/llama.cpp) 
    - should look like `MyLlama\llama.cpp\server.exe`
2. Build llama.cpp 
    - (This was VERY difficult for me) After many different attempts I used this method (Windows) ->
    1. Download, extract, and run [w64devkit](https://github.com/skeeto/w64devkit/releases).exe
    2. `cd` to `llama.cpp` folder
    3. run `make`
    - It can take around 30 minutes to build.
    - Some errors that appear to be stalling are just the program taking a while so be patient!
3. Inside the `llama.cpp\models` folder place `llama-2-7b-chat.Q2_K.gguf`
    - [Download Website](https://huggingface.co/TheBloke/Llama-2-7B-Chat-GGUF/tree/mai)
    - [Instant Download](https://huggingface.co/TheBloke/Llama-2-7B-Chat-GGUF/resolve/main/llama-2-7b-chat.Q2_K.gguf?download=true)
    

