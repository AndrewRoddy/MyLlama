from llama_cpp import Llama

def ask_llama(message="Say ERROR back to me",
              model_path=".venv\\models\\llama-2-7b-chat.Q2_K.gguf",
              verbose=False,
              system_message="Q: In english.",
              max_tokens=64
              ):
    # Put the location of to the GGUF model that you've download from HuggingFace here
    llm = Llama(model_path=model_path,verbose=verbose)

    # Prompt creation
    prompt = f"{system_message} {message} A: "

    # Run the model
    output = llm(prompt,max_tokens=max_tokens,stop=["Q:", "\n"]) # Generate a completion, can also call create_completion

    print(output["choices"][0]["text"])
   
def main():
    message = "1"
    while(message != "0"):
        ask = input("Input: ")
        ask_llama(ask)
        
if __name__ == "__main__":
    main()