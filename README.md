

Steps to make this work:
1. Put llama.cpp into a folder next to this
    - [Download Website](https://github.com/ggerganov/llama.cpp) 
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

