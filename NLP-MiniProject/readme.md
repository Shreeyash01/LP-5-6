# Natural language to No-Sql

This is a NLP project designed to demonstrate the capabilities of natural language processing using the T5 model to generate NoSQL queries based on natural language input. The project includes static and template folders, along with the main application file (`main.py`).

## Features

- Flask web application
- Static files for styling and scripts
- HTML templates for rendering web pages
- Integration with a pre-trained T5 model (model folder excluded from the repository)
- Natural language processing to generate NoSQL queries

## Project Structure

```
.
├── static
│   ├── css
├── templates
│   ├── index.html
├── model (excluded from the repository)
├── main.py
```

## Installation

Follow these steps to set up and run the project on your local machine.

### Prerequisites

- Python 3.x
- `pip` (Python package installer)

### Steps

1. **Clone the repository:**

    ```sh
    git clone https://github.com/yourusername/your-repository-name.git
    cd your-repository-name
    ```

2. **Create and activate a virtual environment:**

    ```sh
    python -m venv venv
    source venv/bin/activate   # On Windows, use `venv\Scripts\activate`
    ```

3. **Download the pre-trained model:**

    The project uses a pre-trained T5 model which is not included in this repository due to its size. You can download the model from the following link:

    [Download Model](https://drive.google.com/drive/u/0/folders/192mee0_jigPaLWu1g78atfkKO8_Kg30b)

    Once downloaded, place the model files in the `model` directory within the project structure.

4. **Run the application:**

    ```sh
    python main.py
    ```

6. **Access the application:**

    Open your web browser and go to `http://127.0.0.1:5000/`.

## Usage

To use the project, follow these steps:

1. Open the web application in your browser.
2. Enter a natural language query into the input field.
3. Submit the query to receive a generated NoSQL query as a result.

### Example

If you enter: 

```
Find all documents from users
```

The application will generate a corresponding NoSQL query using the T5 model.

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request for any improvements.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
