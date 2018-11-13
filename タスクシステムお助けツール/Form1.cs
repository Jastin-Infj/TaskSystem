using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace タスクシステムお助けツール
{
    public partial class First : Form
    {
        public First()
        {
            InitializeComponent();
        }


        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            if(this.Check_MathMozi(sender.ToString().ToCharArray()))
            {
                this.Text = "";
            }
        }


        //文字列に数字以外がないかを判定します
        private bool Check_MathMozi(char[] checkString)
        {
            for (int i = 0; i < checkString.Length; ++i)
            {
                if (checkString[i] <= '0' && checkString[i] >= '9')
                {
                    return false;
                }
            }
            return true;
        }

        private void saveData_Click(object sender, EventArgs e)
        {
            DialogResult dialogResult =  MessageBox.Show("データをセーブしますか?","保存",MessageBoxButtons.YesNo, MessageBoxIcon.Exclamation);
            if(dialogResult == DialogResult.Yes)
            {
                //テキストデータを保存する
                StreamWriter stream = new System.IO.StreamWriter("CreateData/data.txt", true, System.Text.Encoding.GetEncoding("Shift_Jis"));

                //書き込むこと
                stream.WriteLine("タスクシーン名" + "," + tasksceceName.Text);
                stream.WriteLine("タスクタグ名" + "," + tasktagName.Text);
                stream.WriteLine("描画順番" + "," + orderRender.Value);

                stream.Close();
            }
        }
    }
}
