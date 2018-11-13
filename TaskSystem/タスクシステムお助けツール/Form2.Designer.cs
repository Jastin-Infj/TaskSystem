namespace タスクシステムお助けツール
{
    partial class SceceGameObject
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.panel1 = new System.Windows.Forms.Panel();
            this.orderRender = new System.Windows.Forms.NumericUpDown();
            this.label_orderRender = new System.Windows.Forms.Label();
            this.panel2 = new System.Windows.Forms.Panel();
            this.label1 = new System.Windows.Forms.Label();
            this.label_initPositionZ = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.initPositionZ = new System.Windows.Forms.NumericUpDown();
            this.numericUpDown1 = new System.Windows.Forms.NumericUpDown();
            this.label3 = new System.Windows.Forms.Label();
            this.numericUpDown2 = new System.Windows.Forms.NumericUpDown();
            this.tasktagName = new System.Windows.Forms.TextBox();
            this.label_tasktagName = new System.Windows.Forms.Label();
            this.label_tasksceceName = new System.Windows.Forms.Label();
            this.tasksceceName = new System.Windows.Forms.TextBox();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.orderRender)).BeginInit();
            this.panel2.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.initPositionZ)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown2)).BeginInit();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.orderRender);
            this.panel1.Controls.Add(this.label_orderRender);
            this.panel1.Controls.Add(this.panel2);
            this.panel1.Controls.Add(this.tasktagName);
            this.panel1.Controls.Add(this.label_tasktagName);
            this.panel1.Controls.Add(this.label_tasksceceName);
            this.panel1.Controls.Add(this.tasksceceName);
            this.panel1.Location = new System.Drawing.Point(12, 12);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(424, 353);
            this.panel1.TabIndex = 11;
            // 
            // orderRender
            // 
            this.orderRender.DecimalPlaces = 1;
            this.orderRender.Location = new System.Drawing.Point(107, 105);
            this.orderRender.Maximum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.orderRender.Name = "orderRender";
            this.orderRender.Size = new System.Drawing.Size(80, 19);
            this.orderRender.TabIndex = 11;
            // 
            // label_orderRender
            // 
            this.label_orderRender.AutoSize = true;
            this.label_orderRender.Location = new System.Drawing.Point(25, 112);
            this.label_orderRender.Name = "label_orderRender";
            this.label_orderRender.Size = new System.Drawing.Size(53, 12);
            this.label_orderRender.TabIndex = 10;
            this.label_orderRender.Text = "描画順番";
            // 
            // panel2
            // 
            this.panel2.Controls.Add(this.label1);
            this.panel2.Controls.Add(this.label_initPositionZ);
            this.panel2.Controls.Add(this.label2);
            this.panel2.Controls.Add(this.initPositionZ);
            this.panel2.Controls.Add(this.numericUpDown1);
            this.panel2.Controls.Add(this.label3);
            this.panel2.Controls.Add(this.numericUpDown2);
            this.panel2.Location = new System.Drawing.Point(22, 225);
            this.panel2.Name = "panel2";
            this.panel2.Size = new System.Drawing.Size(297, 84);
            this.panel2.TabIndex = 9;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(113, 14);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(65, 12);
            this.label1.TabIndex = 10;
            this.label1.Text = "初期座標値";
            // 
            // label_initPositionZ
            // 
            this.label_initPositionZ.AutoSize = true;
            this.label_initPositionZ.Location = new System.Drawing.Point(205, 45);
            this.label_initPositionZ.Name = "label_initPositionZ";
            this.label_initPositionZ.Size = new System.Drawing.Size(36, 12);
            this.label_initPositionZ.TabIndex = 10;
            this.label_initPositionZ.Text = "Z座標";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(100, 43);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(36, 12);
            this.label2.TabIndex = 9;
            this.label2.Text = "Y座標";
            // 
            // initPositionZ
            // 
            this.initPositionZ.DecimalPlaces = 2;
            this.initPositionZ.Location = new System.Drawing.Point(247, 43);
            this.initPositionZ.Name = "initPositionZ";
            this.initPositionZ.Size = new System.Drawing.Size(48, 19);
            this.initPositionZ.TabIndex = 8;
            // 
            // numericUpDown1
            // 
            this.numericUpDown1.DecimalPlaces = 2;
            this.numericUpDown1.Location = new System.Drawing.Point(151, 43);
            this.numericUpDown1.Name = "numericUpDown1";
            this.numericUpDown1.Size = new System.Drawing.Size(48, 19);
            this.numericUpDown1.TabIndex = 7;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(4, 45);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(36, 12);
            this.label3.TabIndex = 6;
            this.label3.Text = "X座標";
            // 
            // numericUpDown2
            // 
            this.numericUpDown2.DecimalPlaces = 2;
            this.numericUpDown2.Location = new System.Drawing.Point(46, 43);
            this.numericUpDown2.Name = "numericUpDown2";
            this.numericUpDown2.Size = new System.Drawing.Size(48, 19);
            this.numericUpDown2.TabIndex = 5;
            // 
            // tasktagName
            // 
            this.tasktagName.Location = new System.Drawing.Point(107, 66);
            this.tasktagName.Name = "tasktagName";
            this.tasktagName.Size = new System.Drawing.Size(125, 19);
            this.tasktagName.TabIndex = 3;
            // 
            // label_tasktagName
            // 
            this.label_tasktagName.AutoSize = true;
            this.label_tasktagName.Location = new System.Drawing.Point(33, 69);
            this.label_tasktagName.Name = "label_tasktagName";
            this.label_tasktagName.Size = new System.Drawing.Size(34, 12);
            this.label_tasktagName.TabIndex = 2;
            this.label_tasktagName.Text = "タグ名";
            // 
            // label_tasksceceName
            // 
            this.label_tasksceceName.AutoSize = true;
            this.label_tasksceceName.Location = new System.Drawing.Point(20, 36);
            this.label_tasksceceName.Name = "label_tasksceceName";
            this.label_tasksceceName.Size = new System.Drawing.Size(71, 12);
            this.label_tasksceceName.TabIndex = 1;
            this.label_tasksceceName.Text = "タスクシーン名";
            // 
            // tasksceceName
            // 
            this.tasksceceName.Location = new System.Drawing.Point(107, 33);
            this.tasksceceName.Name = "tasksceceName";
            this.tasksceceName.Size = new System.Drawing.Size(125, 19);
            this.tasksceceName.TabIndex = 0;
            // 
            // SceceGameObject
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(555, 440);
            this.Controls.Add(this.panel1);
            this.Name = "SceceGameObject";
            this.Text = "オブジェクトツール";
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.orderRender)).EndInit();
            this.panel2.ResumeLayout(false);
            this.panel2.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.initPositionZ)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown2)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.NumericUpDown orderRender;
        private System.Windows.Forms.Label label_orderRender;
        private System.Windows.Forms.Panel panel2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label_initPositionZ;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.NumericUpDown initPositionZ;
        private System.Windows.Forms.NumericUpDown numericUpDown1;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.NumericUpDown numericUpDown2;
        private System.Windows.Forms.TextBox tasktagName;
        private System.Windows.Forms.Label label_tasktagName;
        private System.Windows.Forms.Label label_tasksceceName;
        private System.Windows.Forms.TextBox tasksceceName;
    }
}