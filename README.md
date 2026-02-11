# Llama cpp runner

## Steps to build repository
#### Clone llama.cpp directory in source folder
```
git clone https://github.com/ggml-org/llama.cpp
```

Make sure you directory looks like this
```
|-- llama.cpp
|-- myllama
|   |-- main.cpp
|   |-- output.txt
|   README.md
```

#### Run CMake in the llama.cpp directory
Switch to the proper directory. 
```
cd llama.cpp
```
Then run CMake commands
```
cmake -B build
```
Run the next command (this took my computer ~19 minutes)
```
cmake --build build --config Release
```

#### Download the gguf to run the model in the models folder
Go into the models folder
```
cd models
```
Download the model into the folder (took my computer ~9 minutes)
```
curl.exe -L -o llama-2-7b-chat.Q2_K.gguf https://huggingface.co/TheBloke/Llama-2-7B-Chat-GGUF/resolve/main/llama-2-7b-chat.Q2_K.gguf
```
#### Run myllama
Go back into the myllama folder
```
cd ../../myllama
```
Compile then run myllama (main.cpp)
```
g++ main.cpp
./a.exe
```
Then just type in your prompt to ask a question
