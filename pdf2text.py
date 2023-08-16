from pdfminer.pdfinterp import PDFResourceManager
from pdfminer.converter import TextConverter
from pdfminer.pdfinterp import PDFPageInterpreter
from pdfminer.pdfpage import PDFPage
from pdfminer.layout import LAParams
from io import StringIO

pdf_file_path = "./ABC157.pdf"

with open(pdf_file_path , "rb") as pdf_file: #ファイルオブジェクトを受け取り、変数「pdf_file」に代入。
    output = StringIO() #コンソールに出力されたテキストを取得するため、IOクラス「StringIO」使用
    resource_manager = PDFResourceManager()
    laparams = LAParams()#レイアウトの変更がなければデフォルトのままで
    text_converter = TextConverter(resource_manager, output, laparams=laparams)
    page_interpreter = PDFPageInterpreter(resource_manager, text_converter)

    for i_page in PDFPage.get_pages(pdf_file): #1ベージずづ処理
        page_interpreter.process_page(i_page)

    output_text = output.getvalue()
    output.close()
    text_converter.close()

print(output_text)
