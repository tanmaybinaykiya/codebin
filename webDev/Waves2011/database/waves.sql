-- phpMyAdmin SQL Dump
-- version 2.8.0.1
-- http://www.phpmyadmin.net
-- 
-- Host: custsqlmoo06
-- Generation Time: Sep 10, 2011 at 05:40 PM
-- Server version: 5.0.91
-- PHP Version: 4.4.9
-- 
-- Database: `waves`
-- 

-- --------------------------------------------------------

-- 
-- Table structure for table `accomodation`
-- 

CREATE TABLE `accomodation` (
  `id` int(11) NOT NULL auto_increment,
  `user_id` int(11) NOT NULL,
  `number_of_boys` int(11) default NULL,
  `number_of_girls` int(11) default NULL,
  `arrival` int(2) default NULL,
  `departure` int(2) default NULL,
  `filename` varchar(30) NOT NULL,
  `Submitted` tinyint(1) NOT NULL default '0',
  `registration_date` date default NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- 
-- Dumping data for table `accomodation`
-- 


-- --------------------------------------------------------

-- 
-- Table structure for table `event_registrations`
-- 

CREATE TABLE `event_registrations` (
  `id` int(11) unsigned NOT NULL auto_increment,
  `user_id` int(11) NOT NULL,
  `event` varchar(50) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- 
-- Dumping data for table `event_registrations`
-- 


-- --------------------------------------------------------

-- 
-- Table structure for table `temp_users`
-- 

CREATE TABLE `temp_users` (
  `id` int(11) NOT NULL auto_increment,
  `email` varchar(255) NOT NULL,
  `password` varchar(40) NOT NULL,
  `name` varchar(100) NOT NULL,
  `mobile` varchar(10) NOT NULL,
  `college` varchar(255) NOT NULL,
  `verify_key` varchar(52) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=latin1 AUTO_INCREMENT=2 ;

-- 
-- Dumping data for table `temp_users`
-- 


-- --------------------------------------------------------

-- 
-- Table structure for table `users`
-- 

CREATE TABLE `users` (
  `id` int(11) NOT NULL auto_increment,
  `email` varchar(255) NOT NULL,
  `password` varchar(40) NOT NULL,
  `name` varchar(100) NOT NULL,
  `mobile` varchar(10) NOT NULL,
  `college` varchar(255) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM AUTO_INCREMENT=2 DEFAULT CHARSET=latin1 AUTO_INCREMENT=2 ;

-- 
-- Dumping data for table `users`
-- 

INSERT INTO `users` VALUES (1, 'bhaavanmerchant@gmail.com', '6d0007e52f7afb7d5a0650b0ffb8a4d1', 'bhaavan', '99', 'BITS');
