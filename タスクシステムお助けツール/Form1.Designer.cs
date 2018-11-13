namespace タスクシステムお助けツール
{
    partial class First
    {
        /// <summary>
        /// 必要なデザイナー変数です。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 使用中のリソースをすべてクリーンアップします。
        /// </summary>
        /// <param name="disposing">マネージ リソースを破棄する場合は true を指定し、その他の場合は false を指定します。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows フォーム デザイナーで生成されたコード

        /// <summary>
        /// デザイナー サポートに必要なメソッドです。このメソッドの内容を
        /// コード エディターで変更しないでください。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.errorProvider1 = new System.Windows.Forms.ErrorProvider(this.components);
            this.tasksceceName = new System.Windows.Forms.TextBox();
            this.label_tasksceceName = new System.Windows.Forms.Label();
            this.label_tasktagName = new System.Windows.Forms.Label();
            this.tasktagName = new System.Windows.Forms.TextBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.orderRender = new System.Windows.Forms.NumericUpDown();
            this.label_orderRender = new System.Windows.Forms.Label();
            this.saveData = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.errorProvider1)).BeginInit();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.orderRender)).BeginInit();
            this.SuspendLayout();
            // 
            // errorProvider1
            // 
            this.errorProvider1.ContainerControl = this;
            // 
            // tasksceceName
            // 
            this.tasksceceName.Location = new System.Drawing.Point(107, 33);
            this.tasksceceName.Name = "tasksceceName";
            this.tasksceceName.Size = new System.Drawing.Size(125, 19);
            this.tasksceceName.TabIndex = 0;
            this.tasksceceName.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
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
            // label_tasktagName
            // 
            this.label_tasktagName.AutoSize = true;
            this.label_tasktagName.Location = new System.Drawing.Point(33, 69);
            this.label_tasktagName.Name = "label_tasktagName";
            this.label_tasktagName.Size = new System.Drawing.Size(34, 12);
            this.label_tasktagName.TabIndex = 2;
            this.label_tasktagName.Text = "タグ名";
            // 
            // tasktagName
            // 
            this.tasktagName.Location = new System.Drawing.Point(107, 66);
            this.tasktagName.Name = "tasktagName";
            this.tasktagName.Size = new System.Drawing.Size(125, 19);
            this.tasktagName.TabIndex = 3;
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.orderRender);
            this.panel1.Controls.Add(this.label_orderRender);
            this.panel1.Controls.Add(this.tasktagName);
            this.panel1.Controls.Add(this.label_tasktagName);
            this.panel1.Controls.Add(this.label_tasksceceName);
            this.panel1.Controls.Add(this.tasksceceName);
            this.panel1.Location = new System.Drawing.Point(12, 21);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(262, 164);
            this.panel1.TabIndex = 9;
            // 
            // orderRender
            // 
            this.orderRender.DecimalPlaces = 1;
            this.orderRender.Increment = new decimal(new int[] {
            1,
            0,
            0,
            65536});
            this.orderRender.Location = new System.Drawing.Point(118, 105);
            this.orderRender.Maximum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.orderRender.Name = "orderRender";
            this.orderRender.Size = new System.Drawing.Size(80, 19);
            this.orderRender.TabIndex = 12;
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
            // saveData
            // 
            this.saveData.Location = new System.Drawing.Point(47, 218);
            this.saveData.Name = "saveData";
            this.saveData.Size = new System.Drawing.Size(202, 48);
            this.saveData.TabIndex = 10;
            this.saveData.Text = "データを保存する";
            this.saveData.UseVisualStyleBackColor = true;
            this.saveData.Click += new System.EventHandler(this.saveData_Click);
            // 
            // First
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(329, 294);
            this.Controls.Add(this.saveData);
            this.Controls.Add(this.panel1);
            this.Name = "First";
            this.Text = "タスクシステム支援ツール";
            ((System.ComponentModel.ISupportInitialize)(this.errorProvider1)).EndInit();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.orderRender)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.ErrorProvider errorProvider1;
        private System.Windows.Forms.TextBox tasksceceName;
        private System.Windows.Forms.Label label_tasksceceName;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.TextBox tasktagName;
        private System.Windows.Forms.Label label_tasktagName;
        private System.Windows.Forms.Label label_orderRender;
        private System.Windows.Forms.NumericUpDown orderRender;
        private System.Windows.Forms.Button saveData;
    }
}

