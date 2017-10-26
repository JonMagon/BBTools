using System;
using System.Drawing;
using System.Runtime.InteropServices;
using System.Windows.Forms;
using BBData;

namespace SpriteViewer
{
    public partial class Form1 : Form
    {
        private Palettes.TypePalette palette = Palettes.TypePalette.SUMMER_PALETTE;

        private BOXFile video;

        public Form1()
        {
            InitializeComponent();
            SendMessage(filter.Handle, 0x1501, 1, "Search"); // EM_SETCUEBANNER
            paletteBox.Text = "SUMMER_PALETTE";
        }

        [DllImport("user32.dll")]
        private static extern IntPtr SendMessage(IntPtr hWnd, int Msg, int wParam,
            [MarshalAs(UnmanagedType.LPWStr)] string lParam);

        private void openToolStripMenuItem_Click(object sender, EventArgs e)
        {
            using (var openFileDialog = new OpenFileDialog())
            {
                openFileDialog.Filter = "Resource archive (*.box) | *.box";

                if (openFileDialog.ShowDialog() == DialogResult.OK)
                {
                    try
                    {
                        video = new BOXFile(openFileDialog.FileName);
                    }
                    catch (Exception ex)
                    {
                        MessageBox.Show(ex.Message,
                            "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    }

                    filter.Enabled = true;

                    spritesBox.Clear();
                    status.Text = null;

                    filesBox.BeginUpdate();

                    filesBox.Items.Clear();

                    foreach (var item in video.Entries)
                        filesBox.Items.Add(item.Filename);

                    filesBox.EndUpdate();
                }
            }
        }

        private void filesBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            LoadMFB();
        }

        private void LoadMFB()
        {
            if (filesBox.SelectedIndex == -1) return;

            try
            {
                var mfb = new MFBFile(video.Entries.Find(
                    item => item.Filename == filesBox.SelectedItem.ToString()).Data, palette);

                status.Text = $"Size: {mfb.Width} x {mfb.Height} | Offset: ({mfb.Offset.X}, {mfb.Offset.Y})";
                if (mfb.IsTransparent) status.Text += " | Transparent";
                if (mfb.IsCompressed) status.Text += " | Compressed";
                if (mfb.IsUnknown) status.Text += " | IsUnknown";

                var imglist = new ImageList();
                spritesBox.LargeImageList = imglist;

                // Scaling
                imglist.ImageSize = new Size(
                    mfb.Width <= 256 ? mfb.Width : 256,
                    mfb.Height <= 256 ? mfb.Height : 256);
                imglist.Images.AddRange(mfb.Entries.ToArray());

                spritesBox.BeginUpdate();
                spritesBox.Items.Clear();
                for (var i = 0; i < mfb.Entries.Count; i++)
                    spritesBox.Items.Add(new ListViewItem(i.ToString(), i));
                spritesBox.EndUpdate();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message,
                    "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void filter_TextChanged(object sender, EventArgs e)
        {
            filesBox.BeginUpdate();
            filesBox.Items.Clear();
            foreach (var item in video.Entries)
                if (item.Filename.Contains(filter.Text))
                    filesBox.Items.Add(item.Filename);
            filesBox.EndUpdate();
        }

        private void paletteBox_SelectedIndexChanged(object sender, EventArgs e)
        {
            switch (paletteBox.Text)
            {
                case "PALETTE":
                    palette = Palettes.TypePalette.PALETTE;
                    break;
                case "AUTUMN_PALETTE":
                    palette = Palettes.TypePalette.AUTUMN_PALETTE;
                    break;
                case "WINTER_PALETTE":
                    palette = Palettes.TypePalette.WINTER_PALETTE;
                    break;
                case "SUMMER_PALETTE":
                    palette = Palettes.TypePalette.SUMMER_PALETTE;
                    break;
                case "SPRING_PALETTE":
                    palette = Palettes.TypePalette.SPRING_PALETTE;
                    break;
                case "MISSIONPALETTE":
                    palette = Palettes.TypePalette.MISSIONPALETTE;
                    break;
                case "LOADINGPALETTE":
                    palette = Palettes.TypePalette.LOADINGPALETTE;
                    break;
                case "TITLEPALETTE":
                    palette = Palettes.TypePalette.TITLEPALETTE;
                    break;
            }
            LoadMFB();
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Close();
        }
    }
}