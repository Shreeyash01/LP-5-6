from flask import Flask, render_template, request
from transformers import T5ForConditionalGeneration, T5Tokenizer
import torch

app = Flask(__name__)

# Load the saved model and tokenizer
model_path = r"D:\CODES\BE-Mini-Projects\NLP-MiniProject\Model"
tokenizer_path = r"D:\CODES\BE-Mini-Projects\NLP-MiniProject\Model"
model = T5ForConditionalGeneration.from_pretrained(model_path)
tokenizer = T5Tokenizer.from_pretrained(tokenizer_path)

def generate_query(question, model, tokenizer):
    # Prepend 'question:' to the input question
    input_text = "question: " + question
    # Encode the input text
    input_ids = tokenizer.encode(input_text, return_tensors="pt", add_special_tokens=True)
    # Generate the output (query)
    output_ids = model.generate(input_ids, max_length=512, num_beams=5, early_stopping=True)
    # Decode and return the generated text
    query = tokenizer.decode(output_ids[0], skip_special_tokens=True)
    return query

@app.route('/', methods=['GET', 'POST'])
def index():
    query = ""
    if request.method == 'POST':
        question = request.form['question']
        query = generate_query(question, model, tokenizer)
    return render_template('index.html', query=query)

if __name__ == '__main__':
    app.run(debug=True)
