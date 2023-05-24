package com.hello;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.*;
import java.util.Timer;
import java.util.TimerTask;

import javax.swing.border.Border;
public class Main{
	static int hour=9,minute=59,second=50;
	static Timer t = new Timer();
	public static void main(String[] args) {
		JFrame frame = new JFrame();
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(600, 500);
		frame.setResizable(false);
		
		JPanel panel = new JPanel();
		panel.setBackground(Color.RED);
		
		JPanel time = new JPanel();
		time.setBackground(Color.GREEN);
		time.setLayout(new FlowLayout(FlowLayout.LEADING,10,10));
		
		JButton btn_increment = new JButton();
		ImageIcon increment = new ImageIcon("Increment.png");
		btn_increment.setPreferredSize(new Dimension(150,150));
		btn_increment.setFocusable(false);
		btn_increment.setIcon(increment);
		
		JLabel timer_screen = new JLabel("00:00:00");
		timer_screen.setFont(new Font("times",Font.BOLD,45));
		Border border = BorderFactory.createLineBorder(Color.BLACK,3);
		timer_screen.setBorder(border);
		
		JButton btn_decrement = new JButton();
		ImageIcon decrement = new ImageIcon("Decrement.png");
		btn_decrement.setPreferredSize(new Dimension(150,150));
		btn_decrement.setIcon(decrement);
		
		JPanel buttons = new JPanel();
		buttons.setLayout(new GridLayout(5,1));
		buttons.setBackground(Color.YELLOW);
		
		JButton start = new JButton("Start");
		start.setPreferredSize(new Dimension(250,50));
		start.setFocusable(false);
		start.setFont(new Font("times",Font.BOLD,25));
		buttons.add(start);
		
		JButton stop = new JButton("Stop");
		stop.setPreferredSize(new Dimension(250,50));
		stop.setFocusable(false);
		stop.setFont(new Font("times",Font.BOLD,25));
		buttons.add(stop);
		
		JButton begin = new JButton("Begin Countdown");
		begin.setPreferredSize(new Dimension(250,50));
		begin.setFont(new Font("times",Font.BOLD,25));
		begin.setFocusable(false);
		begin.setEnabled(false);
		buttons.add(begin);
		
		JButton reset = new JButton("Reset");
		reset.setPreferredSize(new Dimension(250,50));
		reset.setFont(new Font("times",Font.BOLD,25));
		reset.setFocusable(false);
		buttons.add(reset);
		
		JButton close = new JButton("Close");
		close.setPreferredSize(new Dimension(250,50));
		close.setFont(new Font("times",Font.BOLD,25));
		close.setFocusable(false);
		buttons.add(close);
		
		close.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				frame.dispose();
			}
		});
	
		start.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(start.isEnabled()==true) {	
					TimerTask t1 = new TimerTask() {
						public void run() {
							second = (second+1)%60;
							if(second==0) {
								minute = (minute+1)%60;
								if(minute==0) {
									hour = (hour+1)%24;
								}
							}
							String current_time = hour+":"+minute+":"+second;
							timer_screen.setText(current_time);
						}
					};
					t.scheduleAtFixedRate(t1,0,1000);
					start.setEnabled(false);
					btn_increment.setEnabled(false);
					btn_decrement.setEnabled(false);
					reset.setEnabled(false);
					begin.setEnabled(false);
				}
			}
		});
		stop.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				t.cancel();
				t = new Timer();
				btn_increment.setEnabled(true);
				btn_decrement.setEnabled(true);
				start.setEnabled(true);
				reset.setEnabled(true);
				if(hour>0 || minute>0 || second>0) {
					begin.setEnabled(true);
				}
			}
		});
		
		reset.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				hour = 0;
				minute = 0;
				second = 0;
				timer_screen.setText("00:00:00");
				begin.setEnabled(false);
			}
		});
		btn_increment.addMouseListener(new MouseAdapter() {
			public void mousePressed(MouseEvent e) {
				if(e.getButton()==MouseEvent.BUTTON1 && btn_increment.isEnabled()==true) {	
					second = (second+1)%60;
					if(second==0) {
						minute = (minute+1)%60;
						if(minute==0) {
							hour = (hour+1)%24;
						}
					}
					String current_time = hour+":"+minute+":"+second;
					timer_screen.setText(current_time);
					begin.setEnabled(true);
				}
			}
		});
		btn_decrement.addMouseListener(new MouseAdapter() {
			public void mousePressed(MouseEvent e) {
				if(e.getButton()==MouseEvent.BUTTON1 && btn_decrement.isEnabled()) {
					if(hour==0  && minute==0 && second==0) {
					}
					else {
						begin.setEnabled(true);
						second--;
						if(second==-1) {
							second=59;
							minute--;
							if(minute==-1) {
								minute=59;
								hour--;
							}
						}
					}
					if(hour==0 && minute==0 && second==0) {
						begin.setEnabled(false);
					}
					String current_time = hour+":"+minute+":"+second;
					timer_screen.setText(current_time);
				}
			}
		});
		begin.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if(hour>0 || minute>0 || second>0) {
					begin.setEnabled(false);
					reset.setEnabled(false);
					start.setEnabled(false);
					btn_increment.setEnabled(false);
					btn_decrement.setEnabled(false);
					TimerTask t2 = new TimerTask() {
						public void run() {
							if(hour==0 && minute==0 && second==0) {
								t.cancel();
								t = new Timer();
								btn_increment.setEnabled(true);
								btn_decrement.setEnabled(true);
								start.setEnabled(true);
								reset.setEnabled(true);
							}
							else {
								second--;
								if(second==-1) {
									second=59;
									minute--;
									if(minute==-1) {
										minute=59;
										hour--;
									}
								}
							}
							String current_time = hour+":"+minute+":"+second;
							timer_screen.setText(current_time);
						}
					};
					t.scheduleAtFixedRate(t2, 0, 1000);
				}
			}
		});
		time.add(btn_increment);
		time.add(timer_screen);
		time.add(btn_decrement);
		panel.add(time);
		panel.add(buttons);
		frame.add(panel);
		frame.setVisible(true);
	}
}