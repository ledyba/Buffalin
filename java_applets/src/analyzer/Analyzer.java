package analyzer;

import java.awt.*;
import java.awt.event.*;
import java.applet.*;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JLabel;
import javax.swing.*;

/**
 * <p>�^�C�g��: �������</p>
 *
 * <p>����: ��������͂��܂�</p>
 *
 * <p>���쌠: Copyright (c) 2006 PSI</p>
 *
 * <p>��Ж�: �Ձi�v�T�C�j�̋����֐S���</p>
 *
 * @author ������
 * @version 1.0
 */


public class Analyzer extends Applet {
    boolean isStandalone = false;
    BorderLayout borderLayout1 = new BorderLayout();
    JPanel jPanel1 = new JPanel();
    BorderLayout borderLayout2 = new BorderLayout();
    GridBagLayout gridBagLayout1 = new GridBagLayout();
    JScrollPane jScrollPane1 = new JScrollPane();
    JTextArea ResultField = new JTextArea();
    JButton AnalyzeButton = new JButton();
    JTextField ThingField = new JTextField();
    JLabel jLabel1 = new JLabel();
    JPanel CopyRightPanel = new JPanel();
    JLabel CopyRightField = new JLabel();
    GridBagLayout gridBagLayout2 = new GridBagLayout();
    JLabel CopeRight2 = new JLabel();
    JTextField CopyRight3 = new JTextField();
    JLabel CopyRight4 = new JLabel();
    JLabel CopyRight5 = new JLabel();
    JTextField CopyRight6 = new JTextField();
    JLabel CopyRight1 = new JLabel();
    //�p�����[�^�l�̎擾
    public String getParameter(String key, String def) {
        return isStandalone ? System.getProperty(key, def) :
                (getParameter(key) != null ? getParameter(key) : def);
    }

    //�A�v���b�g�̍\�z
    public Analyzer() {
    }

    //�A�v���b�g�̏�����
    public void init() {
        try {
            jbInit();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    //�R���|�[�l���g�̏�����
    private void jbInit() throws Exception {
        this.setLayout(borderLayout2);
        jPanel1.setLayout(gridBagLayout1);
        ResultField.setEditable(false);
        ResultField.setText("");
        AnalyzeButton.setText("��������͂���");
        AnalyzeButton.addActionListener(new
                                        Analyzer_AnalyzeButton_actionAdapter(this));
        jLabel1.setText("jLabel1");
        CopyRightField.setBorder(BorderFactory.createEtchedBorder());
        CopyRightField.setText(
                "�u������́vfor Java v1.03(2006/04/12)");
        CopyRightPanel.setLayout(gridBagLayout2);
        CopeRight2.setText("�Ձi�v�T�C�j�̋����֐S��ԁF");
        CopyRight3.setEditable(false);
        CopyRight3.setText("http://ledyba.ddo.jp/");
        CopyRight4.setText("Original Program was written by Clock");
        CopyRight5.setToolTipText("");
        CopyRight5.setText("���J�h���R�A���す�F");
        CopyRight6.setEditable(false);
        CopyRight6.setText("http://tekipaki.jp/~clock/");
        CopyRight1.setText("Analyzed & Written by �Ձi�v�T�C�j");
        this.add(jPanel1, java.awt.BorderLayout.CENTER);
        jScrollPane1.getViewport().add(ResultField);
        jPanel1.add(jScrollPane1, new GridBagConstraints(0, 2, 3, 1, 1.0, 1.0
                , GridBagConstraints.CENTER, GridBagConstraints.BOTH,
                new Insets(5, 5, 5, 5), 0, 0));
        jPanel1.add(AnalyzeButton, new GridBagConstraints(2, 0, 1, 2, 0.0, 0.0
                , GridBagConstraints.CENTER, GridBagConstraints.NONE,
                new Insets(5, 0, 0, 5), 0, 0));
        this.add(CopyRightPanel, java.awt.BorderLayout.SOUTH);
        jPanel1.add(ThingField, new GridBagConstraints(0, 1, 2, 1, 1.0, 0.0
                , GridBagConstraints.CENTER, GridBagConstraints.HORIZONTAL,
                new Insets(5, 5, 0, 5), 0, 0));
        CopyRightPanel.add(CopyRight4,
                           new GridBagConstraints(0, 3, 3, 1, 1.0, 0.0
                                                  , GridBagConstraints.WEST,
                                                  GridBagConstraints.BOTH,
                                                  new Insets(0, 5, 0, 0), 0, 0));
        CopyRightPanel.add(CopyRight3,
                           new GridBagConstraints(1, 2, 1, 1, 1.0, 0.0
                                                  , GridBagConstraints.CENTER,
                                                  GridBagConstraints.HORIZONTAL,
                                                  new Insets(0, 0, 0, 5), 0, 0));
        CopyRightPanel.add(CopyRight6,
                           new GridBagConstraints(1, 4, 1, 1, 1.0, 0.0
                                                  , GridBagConstraints.CENTER,
                                                  GridBagConstraints.BOTH,
                                                  new Insets(0, 0, 5, 5), 0, 0));
        CopyRightPanel.add(CopeRight2,
                           new GridBagConstraints(0, 2, 1, 1, 0.0, 0.0
                                                  , GridBagConstraints.WEST,
                                                  GridBagConstraints.NONE,
                                                  new Insets(0, 5, 0, 0), 0, 0));
        CopyRightPanel.add(CopyRight5,
                           new GridBagConstraints(0, 4, 1, 1, 0.0, 0.0
                                                  , GridBagConstraints.WEST,
                                                  GridBagConstraints.NONE,
                                                  new Insets(0, 5, 5, 0), 0, 0));
        CopyRightPanel.add(CopyRight1, new GridBagConstraints(0, 1, 2, 1, 0.0, 0.0
                , GridBagConstraints.CENTER, GridBagConstraints.BOTH,
                new Insets(0, 5, 0, 5), 0, 0)); /*�}�E�X*/
        CopyRightPanel.add(CopyRightField,
                           new GridBagConstraints(0, 0, 2, 1, 1.0, 0.0
                                                  , GridBagConstraints.WEST,
                                                  GridBagConstraints.BOTH,
                                                  new Insets(0, 0, 0, 5), 0, 0));
        ResultField.addMouseListener(new psi.lib.Swing.PopupRightClick(ResultField));
        ThingField.addMouseListener(new psi.lib.Swing.PopupRightClick(ThingField));
        CopyRight3.addMouseListener(new psi.lib.Swing.PopupRightClick(CopyRight3));
        CopyRight6.addMouseListener(new psi.lib.Swing.PopupRightClick(CopyRight6));
    }

    //�A�v���b�g���̎擾
    public String getAppletInfo() {
        return "�A�v���b�g���";
    }

    //�p�����[�^���̎擾
    public String[][] getParameterInfo() {
        return null;
    }

    public void AnalyzeButton_actionPerformed(ActionEvent e) {
        String str = this.ThingField.getText();
        if(str == null || str.equals("")){
            this.ResultField.setText("�������̂���͂��Ă��������B");
            return;
        }
        AnalyzerCore ana = new AnalyzerCore(str);
        this.ResultField.setText(ana.doAnalyze());
    }
}


class Analyzer_AnalyzeButton_actionAdapter implements ActionListener {
    private Analyzer adaptee;
    Analyzer_AnalyzeButton_actionAdapter(Analyzer adaptee) {
        this.adaptee = adaptee;
    }

    public void actionPerformed(ActionEvent e) {

        adaptee.AnalyzeButton_actionPerformed(e);
    }
}
