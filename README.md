# MyLlama

A lightweight C++ command-line interface for [llama.cpp](https://github.com/ggml-org/llama.cpp) for running local Llama models. Enter a prompt, get a response — no server, no Python, no dependencies beyond a C++ compiler.

## Features

- **Simple CLI interface** — type a prompt and get a response
- **Configurable via JSON** — control output length, system prompt, model, and output file through `config.json`
- **Clean output** — automatically strips ANSI escape codes and non-printable characters from model output

## Project Structure

```
MyLlama/
├── llama.cpp/          # llama.cpp (cloned separately)
├── myllama/
│   ├── main.cpp        # Main source code
│   ├── config.json     # Runtime configuration
│   └── output.txt      # Model output (generated)
└── README.md
```

## Setup

### Prerequisites

- A C++ compiler (g++)
- CMake
- curl (for downloading the model)

### 1. Clone llama.cpp

From the project root:

```bash
git clone https://github.com/ggml-org/llama.cpp
```

### 2. Build llama.cpp

```bash
cd llama.cpp
cmake -B build
cmake --build build --config Release
```

**Note:** The build step can take a while (~19 minutes depending on your hardware).

### 3. Download a model

```bash
cd llama.cpp/models
curl -L -o llama-2-7b-chat.Q2_K.gguf https://huggingface.co/TheBloke/Llama-2-7B-Chat-GGUF/resolve/main/llama-2-7b-chat.Q2_K.gguf
```

**Note:** This is a ~3 GB download.

### 4. Compile and run

```bash
cd myllama
g++ main.cpp
./a.exe
```

You will be prompted to enter your question.

## Configuration

Edit `myllama/config.json` to customize behavior:

```json
{
    "length": 99,
    "system_prompt": "In english, ",
    "output_file": "output.txt",
    "model_name": "llama-2-7b-chat.Q2_K.gguf"
}
```

| Field           | Description                                      |
|-----------------|--------------------------------------------------|
| `length`        | Max number of tokens the model will generate     |
| `system_prompt` | Text prepended to your prompt for context        |
| `output_file`   | File where the cleaned response is saved         |
| `model_name`    | GGUF model filename inside `llama.cpp/models/`   |

