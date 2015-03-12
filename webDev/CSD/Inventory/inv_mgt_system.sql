-- phpMyAdmin SQL Dump
-- version 2.11.6
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Apr 12, 2012 at 10:51 AM
-- Server version: 5.0.51
-- PHP Version: 5.2.6

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `inv_mgt_system`
--

-- --------------------------------------------------------

--
-- Table structure for table `accounts`
--

CREATE TABLE `accounts` (
  `id` int(11) NOT NULL auto_increment,
  `loginid` varchar(20) NOT NULL,
  `usertype` varchar(20) NOT NULL,
  `password` varchar(60) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=5 ;

--
-- Dumping data for table `accounts`
--

INSERT INTO `accounts` (`id`, `loginid`, `usertype`, `password`) VALUES
(4, 'admin', 'Super Admin', 'admin');

-- --------------------------------------------------------

--
-- Table structure for table `faculty`
--

CREATE TABLE `faculty` (
  `id` int(11) NOT NULL auto_increment,
  `PSRN` int(3) NOT NULL,
  `LOGINID` varchar(20) NOT NULL,
  `NAME` char(40) NOT NULL,
  `DEPARTMENT` char(20) NOT NULL,
  `CATEGORY` varchar(10) NOT NULL,
  `LOCATION` varchar(10) NOT NULL,
  `COMPUTER` char(20) NOT NULL,
  `IP_O` varchar(30) NOT NULL,
  `IP_R` varchar(20) NOT NULL,
  `CPE` varchar(30) NOT NULL,
  `UPS` varchar(30) NOT NULL,
  `HEADPHONE` varchar(20) NOT NULL,
  `WEBCAM` varchar(20) NOT NULL,
  `MOBILE` varchar(30) NOT NULL,
  `LAPTOP` varchar(30) NOT NULL,
  `PRINTER` varchar(30) NOT NULL,
  `OTHERS` varchar(20) NOT NULL,
  `FLAG` char(2) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=177 ;

--
-- Dumping data for table `faculty`
--

INSERT INTO `faculty` (`id`, `PSRN`, `LOGINID`, `NAME`, `DEPARTMENT`, `CATEGORY`, `LOCATION`, `COMPUTER`, `IP_O`, `IP_R`, `CPE`, `UPS`, `HEADPHONE`, `WEBCAM`, `MOBILE`, `LAPTOP`, `PRINTER`, `OTHERS`, `FLAG`) VALUES
(1, 500, 'omp', 'Om Prakash', 'CCU', 'FACULTY', 'C-205', 'DELL-755', '', '', '8 Port', 'NUM600VA', 'Intex1236er35346', 'Enter', '', 'Dell ™ Vostro A840', 'no', '', '1'),
(3, 33, '', 'Meenal Kowshik', 'BIO', 'FACULTY', 'C-204', 'DELL-755', '7960', '7912', '4 Port', 'NUM600VA', 'Intex', 'Enter', 'Nokia 2626', '', '', '', ''),
(4, 52, '', 'Judith Maria Braganca', 'BIO', 'FACULTY', 'C-205', 'DELL-380', '7912', '7912', '4 Port', 'NUM600VA', '', '', '', 'Dell Vostro 3500', '', '', ''),
(5, 80, '', 'M. Srikanth', 'BIO', 'FACULTY', 'C-201', 'IBM', '7912', '', '', 'NUM600VA', '', '', '', 'Dell Vostro 3500', '', '', ''),
(6, 116, '', 'Anasuya Ganguly', 'BIO', 'FACULTY', 'C-202', 'IBM', '7912', '7912', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(7, 297, '', 'Saby John K.', 'BIO', 'FACULTY', 'B-409', 'DELL-380', '7960', '7912', '4 Port', 'NUM600VA', '', '', '', 'Dell Vostro 3500', '', '', ''),
(8, 82, '', 'Veeky Baths', 'BIO', 'FACULTY', 'CC-216', 'IBM', '7912', '', '2 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(9, 193, '', 'Kuttalaprakash C.', 'BIO', 'FACULTY', 'B-111', 'IBM', '7912', '', '4 Port', '', '', '', '', '', '', '', ''),
(10, 346, '', 'Dibakar Chakraborty', 'BIO', 'FACULTY', 'C-214', 'DELL-380', '7912', '7912', '4 Port', 'NUM600VA', '', '', 'Nokia 2626', '', '', '', ''),
(11, 381, '', 'Vijayashree Nayak', 'BIO', 'FACULTY', 'B-210', 'IBM', '7912', '7912', '4 Port', 'NUM600VA', '', '', 'Nokia 2626', '', '', '', ''),
(12, 412, '', 'Sumit Biswas', 'BIO', 'FACULTY', 'B-110', '', '7912', '', '4 Port', '', '', '', '', 'Laptop', '', '', ''),
(13, 414, '', 'Anghusman Sarkar', 'BIO', 'FACULTY', 'B-308', 'IBM', '7912', '7912', '4 Port', 'NUM600VA', '', '', 'Nokia 2626', '', '', '', ''),
(14, 418, '', 'Gautam Krishnan', 'BIO', 'FACULTY', 'B-316', 'IBM', '7912', '', '2 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(15, 68, '', 'Srinivas Krishnaswamy', 'CHE', 'FACULTY', 'A-301/1', 'DELL-755', '7960', '7912', '4 Port', 'NUM600VA', 'Intex', 'Enter', '', 'Dell™ 3400 n-Series', '', '', ''),
(16, 185, '', 'Sampatrao Dagu Manjare', 'CHE', 'FACULTY', 'A-301/9', 'DELL-330', '7960', '7912', '4 Port(2 No''s)', 'PIN650VA', 'Intex', 'Enter', 'Nokia-C1-02 ', '', '', '', ''),
(17, 4, '', 'Manjuri Kumar', 'CHE', 'FACULTY', 'A-301/7', 'IBM', '7912', '', '', 'NUM600VA', '', '', '', '', '', '', ''),
(18, 172, '', 'Vaishnavi T. Unde', 'CHE', 'FACULTY', 'A-301/3', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(19, 66, '', 'P. Venkateswara Rao', 'CHE', 'FACULTY', 'A-301/2', 'DELL-380', '7912', '7912', '4 Port', 'NUM600VA', '', '', 'Nokia 2626', '', '', '', ''),
(20, 310, '', 'Saroj S. Baral', 'CHE', 'FACULTY', 'A-301/5', 'IBM', '7912', '7912', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(21, 94, '', 'Sutapa Roy Ramanan', 'CHE', 'FACULTY', 'A-301/4', 'DELL-380', '7912', '7912', '4 Port', 'NUM600VA', '', '', '', 'Dell Vostro 3500', '', '', ''),
(22, 311, '', 'Surendran G.', 'CHE', 'FACULTY', 'A-301/16', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(23, 431, '', 'Amol Deshpande', 'CHE', 'FACULTY', 'B-311', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(24, 433, '', 'Ponnani', 'CHE', 'FACULTY', 'A-301/8', 'DELL-360', '7912', '7912', '4 Port', 'NUM600VA', '', '', '', 'Dell Vostro 3500', '', '', ''),
(25, 0, '', '', '', 'FACULTY', '', '', '', '', '', '', '', '', '', '', '', '', 'N'),
(26, 95, '', 'Sunil Bhand', 'CHY', 'FACULTY', 'C-211', 'DELL-755', '7960', '7912', '4 Port', 'NUM600VA', 'Iball', 'Enter', 'Nokia 2626', 'Dell ™ Vostro A840', '', '', ''),
(27, 95, '', 'Sunil Bhand', 'CHY', 'FACULTY', 'C-211', 'IBM', '', '', '', '', '', '', '', '', '', '', ''),
(28, 3, '', 'Aditya P. Koley', 'CHY', 'FACULTY', 'C-213', 'IBM', '7970', '7912', '4 Port', 'NUM600VA', 'Intex', 'Enter', '', 'Dell ™ Vostro A840', '', '', ''),
(29, 85, '', 'Anjan.Chattopadhyay', 'CHY', 'FACULTY', 'C-219', 'IBM', '7912', '7912', '4 Port', 'NUM600VA', '', '', 'Nokia 2626', '', '', '', ''),
(30, 58, '', 'N. N. Ghosh', 'CHY', 'FACULTY', 'C-208', 'DELL-380', '7912', '7912', '4 Port', 'NUM600VA', 'Iball', 'Enter', 'Nokia 2626', 'Dell ™ Vostro1014 n -Series', '', '', ''),
(31, 16, '', 'R N Behera', 'CHY', 'FACULTY', 'C-221', 'DELL 380', '', '', '4 Port', 'NUM600VA', '', '', '', 'Dell Vostro 3500', '', '', 'N'),
(32, 17, '', 'Tincy Thomas', 'CHY', 'FACULTY', 'B-313', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(33, 126, '', 'Rabi N Panda', 'CHY', 'FACULTY', 'B-312', 'DELL-990', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(34, 189, '', 'Rashmi Chauhan', 'CHY', 'FACULTY', 'B-315', 'DELL-990', '7912', '7912', '4 Port', 'NUM600VA', '', '', 'Nokia 2626', '', '', '', ''),
(35, 211, '', 'P. Bhavana', 'CHY', 'FACULTY', 'C-223', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(36, 0, '', '', '', 'FACULTY', '', '', '', '', '', '', '', '', '', '', '', '', 'N'),
(37, 309, '', 'Sujit K Ghosh', 'CHY', 'FACULTY', 'B-112', 'DELL-380', '7912', '7912', '4 Port', 'NUM600VA', '', '', 'Nokia 2626', '', '', '', ''),
(38, 298, '', 'K.P.Jayadevan', 'CHY', 'FACULTY', 'B-309', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(39, 364, '', 'Amrita Chaterjee', 'CHY', 'FACULTY', 'C-222', 'IBM', '7912', '', '', 'NUM600VA', '', '', '', '', '', '', ''),
(40, 363, '', 'Mainak Banarjee', 'CHY', 'FACULTY', 'C-206', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(41, 318, '', 'Halan Prakash', 'CHY', 'FACULTY', 'CC-101', 'IBM(Monitor,KB, Mous', '7912', '7912', '4 Port', 'NUM600VA', '', '', 'Nokia 2626', '', '', '', ''),
(42, 122, '', 'Ranjan Dey', 'CHY', 'FACULTY', 'A-301/6', 'IBM(2 No''s)', '7912', '7912', '4 Port', 'NUM600VA', '', '', 'Nokia 2626', 'Dell Vostro 3500', '', '', ''),
(43, 78, '', 'Bharat M. Deshpande', 'CSI', 'FACULTY', 'A-408', 'DELL-755', '7960', '7912', '4 Port', 'NUM600VA', 'Intex', 'Enter', '', 'Dell ™ Vostro A840', '', '', ''),
(44, 83, '', 'J. V. Rao', 'CSI', 'FACULTY', 'A-410', 'DELL-330', '7960', '7912', '4 Port', '', '', '', '', 'Dell ™ Vostro A840', '', '', ''),
(45, 10, '', 'Neena Goveas', 'CSI', 'FACULTY', 'A-409', 'HP', '7912', '7912', '4 Port', 'NUM600VA', '', '', '', 'Dell ™ Vostro1014 n -Series', '', '', ''),
(46, 69, '', 'Lucy Gudino', 'CSI', 'FACULTY', 'A-406', '', '7912', '', '4 Port', 'NUM600VA', '', '', '', 'Dell Vostro 3500', '', '', ''),
(47, 84, '', 'Mangesh Bedekar', 'CSI', 'FACULTY', 'CC-107', 'DELL-755', '7912', '7912', '4 Port', 'NUM600VA', '', '', '', 'Dell Vostro 3500', '', '', ''),
(48, 111, '', 'Nitin Upadhyay', 'CSI', 'FACULTY', 'A-421', 'IBM', '7912', '7912', '4 Port', 'NUM600VA', '', '', 'Nokia 2626', '', '', '', ''),
(49, 192, '', 'Ramprasad Joshi', 'CSI', 'FACULTY', 'A-405', '', '7912', '', '4 Port', '', '', '', '', 'Dell Vostro 3500', '', '', ''),
(50, 81, '', 'Raghvendra G. S.', 'CSI', 'FACULTY', 'A-402', 'DELL-990', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(51, 296, '', 'Aruna Gavada', 'CSI', 'FACULTY', 'A-423', 'IBM', '7912', '', '2 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(52, 323, '', 'R K Roul', 'CSI', 'FACULTY', 'A-416', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(53, 340, '', 'K.V.Santhilata', 'CSI', 'FACULTY', 'A-420', 'IBM', '7912', '', '4 Port', '', '', '', '', '', '', '', ''),
(54, 114, '', 'S. K. Sahay', 'CSI', 'FACULTY', 'A-407', 'DELL-360', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(55, 366, '', 'Mahadev Gawas', 'CSI', 'FACULTY', 'A-403', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(56, 371, '', 'Biju K Raveendran', 'CSI', 'FACULTY', 'A-413', 'DELL-330', '7912', '', '4 Port', 'NUM600VA', '', '', '', 'Dell Vostro 3500', '', '', ''),
(57, 436, '', 'Shubhangi Gawali', 'CSI', 'FACULTY', 'A-418', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(58, 456, '', 'Geeta Patil', 'CSI', 'FACULTY', 'A-411', 'IBM', '7912', '', ' 2 Port ', 'NUM600VA', '', '', '', '', '', '', ''),
(59, 457, '', 'Sreejith V', 'CSI', 'FACULTY', 'A-416', '', '', '', 'D-Link 3 Port , 4 Port', '', '', '', '', 'Dell Vostro 3500', '', '', ''),
(60, 328, '', 'Mridula Goel', 'ECO', 'FACULTY', 'B-201', 'DELL-755', '7960', '7912', '4 Port', '', 'Intex', 'Enter', 'Nokia 2626', 'Dell Vostro 3500', 'HP LJ 3055', '', ''),
(61, 71, '', 'Debasis Patnaik', 'ECO', 'FACULTY', 'A-302', 'IBM', '7912', '', '', 'NUM600VA', '', '', '', '', '', '', ''),
(62, 332, '', 'Ambili K.', 'ECO', 'FACULTY', 'A-308', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(63, 327, '', 'Kubendran', 'ECO', 'FACULTY', 'A-303', 'DELL-360', '7912', '7912', '4 Port(Extender)(Sharing with ', 'NUM600VA', '', '', 'Nokia 2626', '', '', '', ''),
(64, 470, '', 'William Joe', 'ECO', 'FACULTY', 'A-305', 'IBM', '7912', '', '', 'NUM600VA', '', '', '', '', '', '', ''),
(65, 299, '', 'K.R. Anupama', 'EEE', 'FACULTY', 'A-401/5', 'DELL-755', '7960', '7912', '4 Port', 'NUM600VA', 'Iball', 'Enter', '', 'Dell ™ Vostro A840', '', '', ''),
(66, 302, '', 'K.E. Raman', 'EEE', 'FACULTY', 'B-406', 'DELL-330', '7970', '', '', '', 'Intex', '', 'Black Berry Curve 8520', 'ACER ASPIRE ONE –AOD 255', 'HP LJP 3005dn', 'Wireless Mouse(Umax)', ''),
(67, 302, '', 'K.E. Raman', 'EEE', 'FACULTY', '167-A', 'DELL-330', '', '7912(2 No''s)', '4 Port(2 No''s)', 'NUM600VA(2 No''s)', '', '', '', '', 'HP LJ 1007', '', ''),
(68, 7, '', 'M. K. Deshmukh', 'EEE', 'FACULTY', 'B-403', 'DELL-330', '7970', '7912', '4 Port', '', 'Iball', 'Enter', 'Nokia 2626', 'Dell ™ Vostro A840', 'HP LJ CM1312', '', ''),
(69, 64, '', 'Anita Agrawal', 'EEE', 'FACULTY', 'A-404', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(70, 96, '', 'KVRB Prasad', 'EEE', 'FACULTY', 'A-424', 'HP', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(71, 107, '', 'A. Amalin Prince', 'EEE', 'FACULTY', 'A-206/2', 'IBM', '7912', '7912', '4 Port', 'NUM600VA', '', '', 'Nokia 2626', '', '', '', ''),
(72, 119, '', 'Jyotsna Kulkarni', 'EEE', 'FACULTY', 'A-401/2', 'IBM', '7912', '', '', 'NUM600VA', '', '', '', '', '', '', ''),
(73, 197, '', 'C.Balakrishna Moorthy', 'EEE', 'FACULTY', 'B-320', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(74, 292, '', 'M.A.Bhamare', 'EEE', 'FACULTY', 'A-401/3', 'IBM', '7912', '', '', 'NUM600VA', '', '', '', '', '', '', ''),
(75, 210, '', 'Nitin Sharma', 'EEE', 'FACULTY', 'A-206/3', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(76, 226, '', 'Gautam Bacher', 'EEE', 'FACULTY', 'A-426', 'IBM', '7912', '7912', '4 Port', 'NUM600VA', '', '', 'Nokia 2626', '', '', '', ''),
(77, 229, '', 'Chhayadevi M Bhamare', 'EEE', 'FACULTY', 'A-401/3', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(78, 333, '', 'Ramesha .C.K', 'EEE', 'FACULTY', 'A-401/6', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(79, 334, '', 'Pravin Mane', 'EEE', 'FACULTY', 'A-401/4', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(80, 337, '', 'K. Chandram', 'EEE', 'FACULTY', 'A-401/7', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(81, 369, '', 'Sheron Figarado', 'EEE', 'FACULTY', 'A-206/1', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(82, 375, '', 'Vinita George', 'EEE', 'FACULTY', 'A-415', 'IBM', '7912', '', '4 Port(2 No''s)', 'NUM600VA', '', '', '', '', '', '', ''),
(83, 376, '', 'Sarang C Dhongdi', 'EEE', 'FACULTY', 'A-419', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(84, 430, '', 'R . Femi', 'EEE', 'FACULTY', 'A-415', 'IBM', '', '', '', 'NUM600VA', '', '', '', '', '', '', ''),
(85, 432, '', 'Narayan Manjarekar', 'EEE', 'FACULTY', 'B-203', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(86, 367, '', 'Meenakshi Raman', 'HMT', 'FACULTY', 'B-303', 'DELL-360', '7970', '', '', 'NUM600VA', 'Intex', 'Enter', '', 'Dell ™ Vostro A840', 'HP DJ 2568', '', ''),
(87, 35, '', 'R. P. Pradhan', 'HMT', 'FACULTY', 'B-204', 'DELL-380', '7960', '7912', '4 Port', '', 'Intex', 'Enter', 'Nokia 2626', 'Dell ™ Vostro1014 n -Series', '', '', ''),
(88, 113, '', 'Aruna B. Reddy', 'HMT', 'FACULTY', 'A-309', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(89, 23, '', 'Basavadatta Mitra', 'HMT', 'FACULTY', 'A-312', 'IBM', '7912', '7912', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(90, 246, '', 'Manisha Dixit', 'HMT', 'FACULTY', 'CC-106', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(91, 112, '', 'Shalini Upadhyay', 'HMT', 'FACULTY', 'A-306', 'IBM', '7912', '', '', 'NUM600VA', '', '', '', '', '', '', ''),
(92, 123, '', 'ReenaCheruvalath', 'HMT', 'FACULTY', 'CC-206', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(93, 338, '', 'Ashwin Kumar Mishra', 'HMT', 'FACULTY', 'B-310', '', '7912', '7912', '4 Port(Extender)(Sharing with ', '', '', '', 'Nokia 2626', 'Dell Vostro 3500', '', '', ''),
(94, 383, '', 'G.Gyanesh', 'HMT', 'FACULTY', 'A-304', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(95, 420, '', 'K A Geetha', 'HMT', 'FACULTY', 'A-301/20', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(96, 425, '', 'Shikha Sahai', 'HMT', 'FACULTY', 'B-203', 'IBM', '7912', '', '2 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(97, 11, '', 'Reeta S. Dubey', 'MAT', 'FACULTY', 'CC-204', 'DELL-755', '7960', '7912', '4 Port', 'NUM600VA', 'Iball', 'Enter', 'Nokia 2626', 'Dell ™ Vostro A840', 'HP LJ 3020', '', ''),
(98, 93, '', 'Tarkeshwar Singh', 'MAT', 'FACULTY', 'CC-215', '', '7912', '7912', '4 Port(Extender)(Sharing with ', 'NUM600VA', '', '', 'Nokia 2626', 'Dell Vostro 3500', '', '', ''),
(99, 77, '', 'Prassana Kumar', 'MAT', 'FACULTY', 'CC-203', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(100, 121, '', 'P. Dhanumjaya', 'MAT', 'FACULTY', 'CC-209', 'DELL-990', '7912', '7912', '4 Port', 'NUM600VA', '', '', 'Nokia 2626', '', '', '', ''),
(101, 184, '', 'Anil Kumar', 'MAT', 'FACULTY', 'CC-205', 'DELL-990', '7912', '7912', '4 Port(Extender)(Sharing with ', 'PIN650VA', '', '', 'Nokia 2626', '', '', '', ''),
(102, 232, '', 'Jessica Pereira', 'MAT', 'FACULTY', 'CC-116', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(103, 305, '', 'Vaishali Sharma', 'MAT', 'FACULTY', 'CC-208', 'IBM', '7912', '', '', 'NUM600VA', '', '', '', '', '', '', ''),
(104, 343, '', 'Amit Setia', 'MAT', 'FACULTY', 'A-301/21', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(105, 372, '', 'Manoj Kumar Pandey', 'MAT', 'FACULTY', 'A-301/14', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(106, 370, '', 'Vineet Kumar Singh', 'MAT', 'FACULTY', 'A-301/15', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(107, 373, '', 'Bijil Prakash', 'MAT', 'FACULTY', 'A-301/13', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(108, 416, '', 'J.K.Sahoo', 'MAT', 'FACULTY', 'CC-214', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(109, 434, '', 'Muslim Malik', 'MAT', 'FACULTY', 'A-310', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(110, 454, '', 'Sangeeta Jaiswal', 'MAT', 'FACULTY', 'CC-108', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(111, 471, '', 'Myank Goel', 'MAT', 'FACULTY', 'A-301/17', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(112, 472, '', 'Balchand Prajapati', 'MAT', 'FACULTY', 'B-208', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(113, 108, '', 'Pravin M. Singru', 'MEC', 'FACULTY', 'A-313/6', 'DELL-755', '7960', '7912', '4 Port', 'NUM600VA', 'Iball', 'Enter', 'Nokia 2626', 'Dell ™ Vostro A840', '', '', ''),
(114, 437, '', 'B.J.C. Babu', 'MEC', 'FACULTY', 'B-402', 'DELL-330', '7970', '7912', '4 Port', 'NUM600VA', 'Intex', 'Enter', '', 'Dell ™ Vostro A840', '', '', ''),
(115, 6, 'dmk', 'D. M. Kulkarni', 'MEC', 'FACULTY', 'CC-201', 'DELL-360', '7970', '7912', '4 Port(2 No''s)', 'NUM600VA', 'Intex', 'Odyssey', 'Nokia 2626', 'Dell ™ Vostro A840', 'HP LJ 1320', '', ''),
(116, 21, '', 'Vikas Chaudhry', 'MEC', 'FACULTY', 'CC-210', 'DELL-755', '7912', '7912', '4 Port', 'NUM600VA', '', '', '', 'Dell Vostro 3500', '', '', ''),
(117, 56, '', 'Varinder Singh', 'MEC', 'FACULTY', 'A-313/2', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(118, 39, '', 'C. P Kiran', 'MEC', 'FACULTY', 'A-313/7', 'DELL-380', '7912', '7912', '4 Port', 'NUM600VA', '', '', 'Nokia 2626', '', '', '', ''),
(119, 25, '', 'Sachin Waigaonkar', 'MEC', 'FACULTY', 'A-313/8', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(120, 28, '', 'Abhishek Kumar', 'MEC', 'FACULTY', 'A-313/11', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(121, 92, '', 'A. C. Kulkarni', 'MEC', 'FACULTY', 'A-313/3', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', 'Dell Vostro 3500', '', '', ''),
(122, 180, '', 'Shibu Clement', 'MEC', 'FACULTY', 'A-313/12', 'DELL-990', '7912', '7912', '4 Port', 'NUM600VA', '', '', 'Nokia 2626', '', '', '', ''),
(123, 199, '', 'D K Mohanty', 'MEC', 'FACULTY', 'A-313/5', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(124, 212, '', 'Naik Raghavendra', 'MEC', 'FACULTY', 'A-301/18', 'IBM', '7912', '', '', 'NUM600VA', '', '', '', '', '', '', ''),
(125, 228, '', 'Kiran Mali', 'MEC', 'FACULTY', 'A-313/10', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(126, 317, '', 'M Sreedhar Babu', 'MEC', 'FACULTY', 'A-313/9', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(127, 329, '', 'Ram Kumar', 'MEC', 'FACULTY', 'A-313/4', 'HP', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(128, 435, '', 'Mandar Gupte', 'MEC', 'FACULTY', 'A-419', 'IBM', '', '', '3 Port,4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(129, 458, '', 'Hemanth Kumar', 'MEC', 'FACULTY', 'B-207', 'IBM', '7912', '', '', 'NUM600VA', '', '', '', '', '', '', ''),
(130, 72, '', 'V. V. S. N. V. Prasad', 'HMT', 'FACULTY', 'A-311', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(131, 102, '', 'Pinky Pawaskar', 'HMT', 'FACULTY', 'CC-217', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(132, 70, '', 'Patincharath Nandakumar', 'PHY', 'FACULTY', 'CC-207', 'DELL-755', '7960', '7912', '4 Port', 'NUM600VA', 'Intex', 'Enter', 'Nokia 2626', 'Dell ™ Vostro A840', '', '', ''),
(133, 73, '', 'P.N.Deepak', 'PHY', 'FACULTY', 'CC-112', '', '7912', '7912', '4 Port', '', 'Intex', 'Enter', '', 'Dell Vostro 3500', '', '', ''),
(134, 89, '', 'Gaurav Dar', 'PHY', 'FACULTY', 'C-217', 'DELL-330', '7960', '7912', '4 Port', 'NUM600VA', 'Intex', 'Enter', '', 'Dell ™ Vostro A840', '', '', ''),
(135, 2, '', 'Arun V. Kulkarni', 'PHY', 'FACULTY', 'C-209', 'DELL-330', '7970', '7912', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(136, 60, '', 'Suresh. Ramaswamy', 'PHY', 'FACULTY', 'B-215', 'DELL-330(In Physics', '7970', '7912', '4 Port', '', 'Intex', 'Enter', '', 'Dell Vostro 3500', '', '', ''),
(137, 104, '', 'Raghunath A. Ratabole', 'PHY', 'FACULTY', 'CC-114', 'IBM', '7912', '', '4 Port', '', '', '', '', 'Dell Vostro 3500', '', '', ''),
(138, 62, '', 'Radhika Vathsan', 'PHY', 'FACULTY', 'CC-111', '', '7912', '', '', 'NUM600VA', '', '', '', 'Dell Vostro 3500', '', '', ''),
(139, 124, '', 'V. Sunil Kumar', 'PHY', 'FACULTY', 'CC-115', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(140, 120, '', 'Toby Joseph', 'PHY', 'FACULTY', 'CC-218', 'DELL-380', '7912', '', '4 Port', 'NUM600VA', 'Intex', 'Enter', '', '', '', '', ''),
(141, 207, '', 'Mitaxi P. Mehta', 'PHY', 'FACULTY', 'CC-105', 'IBM', '7912', '7912', '4 Port', 'NUM600VA', '', '', 'Nokia 2626', '', '', '', ''),
(142, 237, '', 'Prasanta Kumar Das', 'PHY', 'FACULTY', 'B-314', 'DELL-360', '7912', '7912', '4 Port', '', '', '', 'Nokia 2626', '', '', '', ''),
(143, 362, '', 'Chandradew Sharma', 'PHY', 'FACULTY', 'B-319', 'IBM', '7912', '', '2 Port', 'NUM600VA', '', '', '', 'Dell Vostro 3500', '', '', ''),
(144, 348, '', 'Teny Teresa Jhon', 'PHY', 'FACULTY', 'B-105', 'IBM', '7912', '', '', '', '', '', '', '', '', '', ''),
(145, 377, '', 'Ram Shanker Patil', 'PHY', 'FACULTY', 'CC-110', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(146, 410, '', 'Tarun kumar jha', 'PHY', 'FACULTY', 'B-106', 'IBM', '7912', '', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(147, 459, '', 'Chandu Lamani', 'P D', 'FACULTY', 'SAC', 'IBM', '7912', '', '4 Port(Extender)', 'NUM600VA', '', '', '', '', '', '', ''),
(148, 320, '', 'Mahadev J Suryawanshi', 'AFU', 'FACULTY', 'B-103', 'DELL-360', '7960', '', '', 'NUM600VA', '', '', 'Nokia 2626', 'Dell Vostro 3500', 'HP DJ 656C', '', ''),
(149, 9, '', 'Anand K. Patil', 'MTU', 'FACULTY', 'B-302', 'DELL-330', '7970', '7912', '4 Port', '', '', '', 'Nokia 2626', 'Dell ™ Vostro1014 n -Series', 'HP LJ 1007', '', ''),
(150, 50, '', 'Anuradha Voolapalli', 'LIB', 'FACULTY', 'LIB', 'DELL-380', '7960', '', '', '', 'Intex', 'Enter', '', '', 'HP LJ 1022', '', ''),
(151, 230, '', 'Raghavendra K.M.', 'MED', 'FACULTY', 'MED', 'DELL-755', '7960', '7912', '4 Port', 'NUM600VA', 'Intex', 'Enter', 'Nokia 2626', 'Dell ™ Vostro1014 n -Series', 'HP LJ 1005', '', ''),
(152, 40, '', 'Shaileshkumar Naik', 'MEC', 'STAFF', '', '', '', '', '', '', '', '', 'Nokia 2626', '', '', '', ''),
(153, 148, '', 'Suresh M. Deshbhandari', 'DRO', 'STAFF', '', '', '', '', '', '', '', '', 'Nokia 2626', '', '', '', ''),
(154, 34, '', 'Smita Acharya', 'SWD', 'STAFF', 'B-213', 'WIPRO', '7912', '7912', '4 Port', '', '', '', 'Nokia 2626', '', 'HP LJ 1020', '', ''),
(155, 36, '', 'S. Y. Muralidhara', 'SWD', 'STAFF', 'B-214', 'IBM', '7912', '7912', '4 Port', '', '', '', 'Nokia 2626', '', 'HP LJ 1020', '', ''),
(156, 48, '', 'Gargee Yougesh Dessai', 'CCU', 'STAFF', 'CC-104', 'HP', '7912', '7912', '4 Port', 'PIN650VA', '', '', 'Nokia 2626', 'Dell Vostro 3500', '', '', ''),
(157, 47, '', 'Girish U. Naik', 'MTU', 'STAFF', 'B-305', '', '', '', '', '', '', '', 'Nokia 2626', '', '', '', ''),
(158, 131, '', 'M. R. Dhiman', 'MTU', 'STAFF', 'B-321', 'WIPRO', '7912', '7912', '4 Port', 'NUM600VA', '', '', 'Nokia 2626', '', '', '', ''),
(159, 103, '', 'Sheik Imran M.A.', 'MTU', 'STAFF', 'B-318', '', '', '', '4 Port', 'NUM600VA', '', '', 'Nokia 2626', '', '', '', ''),
(160, 37, '', 'Bhakti G. Naik', 'DRO', 'STAFF', 'B-406', 'DELL-360', '7960', '7912', '4 Port', 'NUM600VA', '', '', 'Nokia 2626, Nokia 3110C', '', 'HP LJ M1522nf', '', ''),
(161, 336, '', 'Ravindra Kumar Jangir', 'CCU', 'STAFF', 'CC-119', '', '', '', '', '', '', '', '', 'HP Compaq nx 7300', '', '', ''),
(162, 277, '', 'Manas Ranjan Jena', 'AVU', 'STAFF', '12-F', '', '', '7912', '', '', '', '', 'Nokia-C1-02 ', '', '', '', ''),
(163, 462, '', 'Vivek Salaskar', 'HST', 'STAFF', 'AH-4(101)', 'WIPRO', '7912', '', '', '', '', '', 'Nokia-C1-02 ', '', 'HP LJ P1007', '8GB Pendrive Sandisk', ''),
(164, 463, '', 'Amit Naik', 'HST', 'STAFF', 'CH-2(101)', 'WIPRO', '7912', '', '', '', '', '', 'Nokia-C1-02 ', '', 'HP LJ P1007', '8GB Pendrive Sandisk', ''),
(165, 465, '', 'Sonali Malik', 'HST', 'STAFF', 'CH-5(136)', 'WIPRO', '7912', '', '', '', '', '', 'Nokia-C1-02 ', '', 'HP LJ P1007', '8GB Pendrive Sandisk', ''),
(166, 287, '', 'Atul Rai', 'PRO', 'STAFF', 'B-205', '', '', '', '', '', '', '', 'Nokia-C1-02 ', '', '', '', ''),
(167, 428, '', 'Utpal Roy', 'BIO', 'STAFF', 'Cc120', 'DELL-755', '', '', '4 Port', 'NUM600VA', 'Intex', 'Enter', '', 'Dell ™ Vostro A840', '', '', 'Y'),
(168, 500, '', 'Nagarshekar', 'MED', 'STAFF', '', '', '', '', '', '', '', '', '', 'Dell Vostro 3500', '', '', '1'),
(169, 501, '', 'Neelima', 'ADMIN', 'STAFF', 'B-', '', '', '', '', '', '', '', '', '', '', '', ''),
(170, 214, '', 'Anjali Dixit', 'ADMIN', 'STAFF', 'B-400/1', 'DELL-380', '7912', '7912', '4 Port', 'NUM600VA', '', '', '', '', '', '', ''),
(176, 428, 'rakesh', 'rakesh kumar', 'cc', 'staff', 'cc-120', 'HP', '', '', '', '', '', '', '', 'YES', '', '', 'Y');

-- --------------------------------------------------------

--
-- Table structure for table `faculty_category_master`
--

CREATE TABLE `faculty_category_master` (
  `faculty_id` int(11) NOT NULL auto_increment,
  `CATEGORY` varchar(80) NOT NULL,
  PRIMARY KEY  (`faculty_id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=4 ;

--
-- Dumping data for table `faculty_category_master`
--

INSERT INTO `faculty_category_master` (`faculty_id`, `CATEGORY`) VALUES
(1, 'Faculty'),
(2, 'Group Leader'),
(3, 'Faculty Incharge');

-- --------------------------------------------------------

--
-- Table structure for table `faculty_incharge`
--

CREATE TABLE `faculty_incharge` (
  `id` int(3) NOT NULL auto_increment,
  `PSRN` int(3) NOT NULL,
  `LOGINID` varchar(20) NOT NULL,
  `NAME` char(40) NOT NULL,
  `DEPARTMENT` char(20) NOT NULL,
  `LOCATION` varchar(10) NOT NULL,
  `COMPUTER` char(20) NOT NULL,
  `IP_PHONE` varchar(30) NOT NULL,
  `CPE` varchar(30) NOT NULL,
  `UPS` varchar(30) NOT NULL,
  `HEADPHONE` varchar(20) NOT NULL,
  `WEBCAM` varchar(20) NOT NULL,
  `LAPTOP` varchar(30) NOT NULL,
  `PRINTER` varchar(30) NOT NULL,
  `OTHERS` varchar(20) NOT NULL,
  `FLAG` char(2) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=137 ;

--
-- Dumping data for table `faculty_incharge`
--

INSERT INTO `faculty_incharge` (`id`, `PSRN`, `LOGINID`, `NAME`, `DEPARTMENT`, `LOCATION`, `COMPUTER`, `IP_PHONE`, `CPE`, `UPS`, `HEADPHONE`, `WEBCAM`, `LAPTOP`, `PRINTER`, `OTHERS`, `FLAG`) VALUES
(1, 185, 'manjare', 'Sampatrao Dagu Manjare', 'RCD', 'RCD/EDD', 'IBM(2 No''s)', '7912', '4 Port', '', '', '', '', 'HP LJ 1005MFP', '', '0'),
(2, 83, 'jvr', 'J. V. Rao', 'CAH', 'CAHU', 'DELL-755,DELL-330,WI', '7912', '', 'DB1 KVA', '', '', '', 'HP LJ 3020', 'D-Link 8 Port Switch', '0'),
(3, 437, 'omp', 'B.J.C. Babu', 'SWD', 'SWD Record', 'IBM,', '7912', '', 'NUM600VA', '', '', '', 'RISOMASTER', '', '0'),
(4, 437, 'omp', 'B.J.C. Babu', 'SWD', 'SWD', 'IBM(5 No''s)', '7912(2 No''s)', '', 'PIN650VA(2 No''s),NUM600VA', '', '', '', 'HP LJ 1020, HP LJ 1320,HP LJ M', '', '0'),
(5, 437, 'omp', 'B.J.C. Babu', 'SWD', 'A- mess', 'IBM, HP', '7912', 'D-Link 3 Port Switch', 'APC,2Nos', '', '', '', '', 'Scanners(4 nos),Patc', '0'),
(6, 437, 'omp', 'B.J.C. Babu', 'SWD', 'C- mess', 'IBM, HP', '7912', 'D-Link 3 Port Switch', 'APC,2Nos', '', '', '', '', '', '0'),
(7, 437, 'omp', 'B.J.C. Babu', 'SWD', '', '', '7912(13 No''s)', '', 'PW 3KVA(13 No''s)', '', '', '', '', 'D-Link 3 Port Switch', '0'),
(8, 437, 'omp', 'B.J.C. Babu', 'SWD', '', '', '7912', '', 'APC 3 KVA', '', '', '', '', '', '0'),
(9, 437, 'omp', 'B.J.C. Babu', 'SWD', 'Meeting Ro', '', '7912', '', '', '', '', '', '', '', '0'),
(10, 6, 'omp', 'D. M. Kulkarni', 'CCU', 'CC', 'WIPRO', '', '', '', '', '', 'HP Compaq nx7300', '', 'USB HDD 500 GB, Sams', '0'),
(11, 6, 'omp', 'D. M. Kulkarni', 'CCU', 'CC-Office', 'HP', '7912', '', 'PIN650VA', '', '', '', 'HP LJ 3020', 'V-Guard Stabilizers(', '0'),
(12, 6, 'omp', 'D. M. Kulkarni', 'CCU', 'CC', 'IBM', '7970', '', 'NUM600VA', '', '', '', '', '4 Port LAN Extenders', '0'),
(13, 6, 'omp', 'D. M. Kulkarni', 'CCU', 'CC119', 'DELL-755(29 No''s), D', '7912(2no),7920, (3nos)', '4 Port', '', 'ISound(3 No''s),Iball', '', '', '', '', '0'),
(14, 6, 'omp', 'D. M. Kulkarni', 'CCU', 'CC219', 'IBM(56 No''s), WIPRO(', '7912', '', 'DB 30 KVA, PW 3KVA,DB 6 KVA(3 ', '', '', '', '', '', '0'),
(15, 6, 'omp', 'D. M. Kulkarni', 'CCU', '', '', '7912', '', 'DB 6 KVA', '', '', '', '', '', '0'),
(16, 6, 'omp', 'D. M. Kulkarni', 'CCU', 'CSD', 'IBM(20 No''s), HP(8 N', '', '', 'NUM600VA', '', '', '', '', '', '0'),
(17, 6, 'omp', 'D. M. Kulkarni', 'CCU', 'CC Store', 'IBM(36 No''s), WIPRO(', '7970(5 No''s),7960(2 No''s), 792', '4 Port', 'PIN650VA(3 No''s),APC(9 No''s), ', 'Isound(8 No''s)', 'Logitech(31 No''s),Od', 'HP 2133 Mini-Note, Dell Vostro', 'SAMSUNG, HP LJ 1007, HP LJ P10', 'D-Link 8 Port Switch', '0'),
(18, 6, 'omp', 'D. M. Kulkarni', 'CCU', 'B Dome,CC,', '', '', '', 'HP(3 No''s), AVO & NUM600VA', '', '', '', '', '', '0'),
(19, 73, 'omp', 'P.N.Deepak', 'AVU', 'Audi-room', 'IBM', '7912', '', 'Emerson 1kVA(33 No''s)', '', '', '', '', 'LCD Projectors(15 No', '0'),
(20, 73, 'omp', 'P.N.Deepak', 'AVU', 'Audi-Contr', 'IBM(2 No''s)', '7912', '', '', '', '', '', '', 'D-Link 3 Port Switch', '0'),
(21, 73, 'omp', 'P.N.Deepak', 'AVU', '', '', '7912', '', '', '', '', '', '', '', '0'),
(22, 73, 'omp', 'P.N.Deepak', 'AVU', 'LT-1', 'DELL-380', '', '', '', '', '', '', '', 'Alarm Clock', '0'),
(23, 73, 'omp', 'P.N.Deepak', 'AVU', 'LT-2', 'DELL-380', '', '', '', '', '', '', '', 'Alarm Clock', '0'),
(24, 73, 'omp', 'P.N.Deepak', 'AVU', 'LT-3', 'DELL-380', '7912', '', '', '', '', '', '', 'Alarm Clock', '0'),
(25, 73, 'omp', 'P.N.Deepak', 'AVU', 'LT-4', 'DELL-380', '', '', '', '', '', '', '', 'Alarm Clock', '0'),
(26, 73, 'omp', 'P.N.Deepak', 'AVU', '', 'IBM', '', '', '', '', '', '', '', 'Alarm Clock', '0'),
(27, 73, 'omp', 'P.N.Deepak', 'AVU', '', 'DELL-990', '', '', '', '', '', '', '', 'Alarm Clock', '0'),
(28, 73, 'omp', 'P.N.Deepak', 'AVU', '', 'DELL-990', '', '', '', '', '', '', '', 'Alarm Clock', '0'),
(29, 73, 'omp', 'P.N.Deepak', 'AVU', '', 'DELL-360', '', '', '', '', '', '', '', 'Alarm Clock', '0'),
(30, 73, 'omp', 'P.N.Deepak', 'AVU', '', 'DELL-360', '', '', '', '', '', '', '', 'Alarm Clock', '0'),
(31, 73, 'omp', 'P.N.Deepak', 'AVU', '', 'DELL-360', '', '', '', '', '', '', '', 'Alarm Clock', '0'),
(32, 73, 'omp', 'P.N.Deepak', 'AVU', '', 'DELL-990', '', '', '', '', '', '', '', 'Alarm Clock', '0'),
(33, 73, 'omp', 'P.N.Deepak', 'AVU', '', 'DELL-360', '', '', '', '', '', '', '', 'Alarm Clock', '0'),
(34, 73, 'omp', 'P.N.Deepak', 'AVU', '', 'IBM', '', '', '', '', '', '', '', 'Alarm Clock', '0'),
(35, 73, 'omp', 'P.N.Deepak', 'AVU', '', 'DELL-360', '', '', '', '', '', '', '', 'Alarm Clock', '0'),
(36, 73, 'omp', 'P.N.Deepak', 'AVU', '', 'IBM', '', '', '', '', '', '', '', 'Alarm Clock', '0'),
(37, 73, 'omp', 'P.N.Deepak', 'AVU', '', 'IBM', '', '', '', '', '', '', '', 'Alarm Clock', '0'),
(38, 73, 'omp', 'P.N.Deepak', 'AVU', '', 'IBM', '', '', '', '', '', '', '', 'Alarm Clock', '0'),
(39, 73, 'omp', 'P.N.Deepak', 'AVU', '', 'IBM', '', '', '', '', '', '', '', 'Alarm Clock', '0'),
(40, 73, 'omp', 'P.N.Deepak', 'AVU', '', 'DELL-380', '', '', '', '', '', '', '', 'Alarm Clock', '0'),
(41, 73, 'omp', 'P.N.Deepak', 'AVU', '', 'DELL-380', '', '', '', '', '', '', '', 'Alarm Clock', '0'),
(42, 73, 'omp', 'P.N.Deepak', 'AVU', '', 'DELL-380', '', '', '', '', '', '', '', 'Alarm Clock', '0'),
(43, 73, 'omp', 'P.N.Deepak', 'AVU', '', 'IBM', '', '', '', '', '', '', '', 'Alarm Clock', '0'),
(44, 73, 'omp', 'P.N.Deepak', 'AVU', '', 'DELL-990', '', '', '', '', '', '', '', 'Alarm Clock', '0'),
(45, 73, 'omp', 'P.N.Deepak', 'AVU', '', 'DELL-380', '', '', '', '', '', '', '', 'Alarm Clock', '0'),
(46, 73, 'omp', 'P.N.Deepak', 'AVU', '', 'DELL-990', '', '', '', '', '', '', '', 'Alarm Clock', '0'),
(47, 73, 'omp', 'P.N.Deepak', 'AVU', '', 'DELL-380', '', '', '', '', '', '', '', 'Alarm Clock', '0'),
(48, 73, 'omp', 'P.N.Deepak', 'AVU', '', 'IBM', '', '', '', '', '', '', '', 'Alarm Clock', '0'),
(49, 73, 'omp', 'P.N.Deepak', 'AVU', '', 'DELL-380', '', '', '', '', '', '', '', 'Alarm Clock', '0'),
(50, 73, 'omp', 'P.N.Deepak', 'AVU', '', 'DELL-990', '', '', '', '', '', '', '', 'Alarm Clock', '0'),
(51, 73, 'omp', 'P.N.Deepak', 'AVU', '', 'DELL-380', '', '', '', '', '', '', '', 'Alarm Clock', '0'),
(52, 73, 'omp', 'P.N.Deepak', 'AVU', 'LC-101', 'DELL-990', '7912', '', 'DB 1KVA', '', '', '', '', '', '0'),
(53, 73, 'omp', 'P.N.Deepak', 'AVU', 'AV-OFFICE', 'IBM(2 No''s)', '7912', '', 'NUM600VA', '', '', '', '', '', '0'),
(54, 73, 'omp', 'P.N.Deepak', 'AVU', 'AV-OFFICE', 'DELL-380& DELL-360(o', '', '', '', '', '', '', '', '', '0'),
(55, 73, 'omp', 'P.N.Deepak', 'AVU', 'Studio Roo', 'HP(2 No''s)', '7960', '', 'DB 3KVA', '', 'Enter', 'HP Compaq nx 7300, Dell ™ Vost', 'HP PS D7168, HP LJ 1020', '8GB Pendrive Sandisk', '0'),
(56, 73, 'omp', 'P.N.Deepak', 'AVU', 'CC- 117', 'DELL-990', '', '', 'NUM600VA', '', '', '', '', '', '0'),
(57, 73, 'omp', 'P.N.Deepak', 'AVU', 'CC Store', 'DELL-990(1)', '', '', '', '', '', '', '', '', '0'),
(58, 89, 'dmk', 'Gaurav Dar', 'PSD', 'Placement ', 'IBM, DELL-755', '7912', '', 'HCL', '', '', '', '', 'D-Link 3 Port Switch', '0'),
(59, 89, 'dmk', 'Gaurav Dar', 'PSD', 'PS-Office', 'IBM', '7912', '', 'NUM600VA', '', '', '', 'HP LJ 3050', 'D-Link 3 Port Switch', '0'),
(60, 89, 'dmk', 'Gaurav Dar', 'PSD', 'Placement ', '', '7912', '', '', '', '', '', '', '', '0'),
(61, 3, 'koleya', 'Aditya P. Koley', 'INS', 'Instructio', 'DELL-360', '7912', '', '', '', '', '', 'HP LJ 1320', 'USB HDD 500 GB', '0'),
(62, 10, 'neena', 'Neena Goveas', 'ARC', 'ARC', 'HP, DELL-360(3 No''s)', '7912', '4 Port', 'HP, NUM600VA(3 No''s),PIN650VA(', '', '', '', 'HP LJ 2420, RISOMASTER(3 No''s)', 'D-Link 8 Port Switch', '0'),
(63, 7, 'computercenter', 'Suresh. Ramaswamy', 'ADM', 'ADMIN', 'IBM(2 No''s)', '7912(2 No''s)', '', 'NUM600VA, PIN650VA', '', '', '', 'HP LJ 3020', 'D-Link 8 Port Switch', '0'),
(64, 7, 'computercenter', 'Suresh. Ramaswamy', 'ADM', 'ADMIN', 'IBM', '7912', '', 'PIN650VA(2 No''s)', '', '', '', 'HP SCANNER 3770', 'D-Link 8 Port Switch', '0'),
(65, 7, 'computercenter', 'Suresh. Ramaswamy', 'ADM', 'ADMIN', 'WIPRO', '', '', '', '', '', '', 'HP LJ 1150', '', '0'),
(66, 7, 'computercenter', 'Suresh. Ramaswamy', 'ADM', '', '', '7912', '', '', '', '', '', '', '', '0'),
(67, 7, 'computercenter', 'Suresh. Ramaswamy', 'ADM', 'GUEST,Lean', '', '7912', '', '', '', '', '', '', '', '0'),
(68, 7, 'computercenter', 'Suresh. Ramaswamy', 'ADM', 'GUEST,Prof', 'DELL-360', '7912', '4 Port', 'NUM600VA', '', '', '', '', '', '0'),
(69, 7, 'computercenter', 'Suresh. Ramaswamy', 'ADM', 'GUEST,Vice', '', '7912', '', '', '', '', '', '', '', '0'),
(70, 320, 'mjsuryawanshi', 'Mahadev J Suryawanshi', 'AFU', 'Accnts', 'IBM(2 No''s), DELL-75', '7912', '4 Port', 'NUM600VA(4 No''s)', '', '', '', 'HP LJ M1005 MFP, HP LJ P1008, ', 'D-Link 8 Port Switch', '0'),
(71, 9, 'akpatil', 'Anand K. Patil', 'MTU', 'Girish', 'WIPRO, HP,', '7912', '', 'NUM600VA', '', '', '', 'HP LJ M1120 MFP', '', '0'),
(72, 9, 'akpatil', 'Anand K. Patil', 'MTU', 'Projects', 'WIPRO,IBM', '7912', '4 Port', '', '', '', '', 'HP DJ D2568', '', '0'),
(73, 9, 'akpatil', 'Anand K. Patil', 'MTU', 'Proj-store', 'IBM', '7912', '', 'NUM600VA', '', '', '', 'HP LJ 1320', '', '0'),
(74, 9, 'akpatil', 'Anand K. Patil', 'MTU', 'Maintenanc', 'IBM', '7912', '', '', '', '', '', '', '', '0'),
(75, 9, 'akpatil', 'Anand K. Patil', 'MTU', 'Maintenanc', 'WIPRO', '7912', '', '', '', '', '', '', '', '0'),
(76, 9, 'akpatil', 'Anand K. Patil', 'MTU', '', '', '7912', '4 Port', '', '', '', '', '', 'Lan Extender (2 nos)', '0'),
(77, 9, 'akpatil', 'Anand K. Patil', 'MTU', '', '', '7912', '4 Port', '', '', '', '', '', '', '0'),
(78, 9, 'akpatil', 'Anand K. Patil', 'MTU', '', '', '7912', '', '', '', '', '', '', '', '0'),
(79, 50, 'anuradhav', 'Anuradha Voolapalli', 'LIB', 'Library', 'IBM(16 No''s), WIPRO(', '7912(2 No''s)', '', 'PIN650VA(4 No''s),NUM600VA,NUM6', '', '', '', 'HP LJ M1120 MFP', '', '0'),
(80, 230, 'drraghu', 'Raghavendra K.M.', 'MED', 'Medical Re', 'IBM(3 No''s),HP, DELL', '7912(5 No''s),7912 ', '4 Port, 4 Port(Extender), 4 Po', 'NUM600VA(6 No''s),PIN650VA, PW3', '', '', '', 'HP LJ M1522NF. HP LJ P1007', '1 Powerware Spikegua', '0'),
(81, 230, '', 'Raghavendra K.M.', '', 'Medical Ce', '', '', '', '', 'Dell Vostro 3500', '', '', '', 'For Nagarshekar', '0'),
(82, 35, 'rppradhan', 'R. P. Pradhan', 'PRO', 'PRO', 'IBM', '', '', '', '', '', '', '', '', '0'),
(83, 35, 'rppradhan', 'R. P. Pradhan', 'PRO', 'Security G', 'IBM', '7912', '4 Port', 'PIN650VA', '', '', '', 'HP LJ 1020', '', '0'),
(84, 35, 'rppradhan', 'R. P. Pradhan', 'PRO', 'VGH Recept', 'HP, IBM', '7912(12 No''s)', '', 'PIN650VA(3 No''s), Emerson ', '', '', '', '', 'Wireless Routers(10 ', '0'),
(85, 35, 'rppradhan', 'R. P. Pradhan', 'PRO', '', '', '7912', '', '', '', '', '', '', '', '0'),
(86, 37, 'bhakti', 'Bhakti G. Naik', 'DRO', 'Conference', 'HP', '7912', '', 'Emerson 1 KVA', '', '', '', '', '', '0'),
(87, 37, 'bhakti', 'Bhakti G. Naik', 'DRO', 'Dir.Off', 'DELL-380', '7912', '', 'NUM600VA', '', '', '', '', '', '0'),
(88, 297, 'saby', 'Saby John K.', 'BITSAA', 'BITSAA', 'DELL-380(4 No''s)', '7912', '', '', 'Intex', '', '', '', '', '0'),
(89, 33, 'meenal', 'Meenal Kowshik', 'CWU', 'Day Care C', 'IBM', '7912', '4 Port', 'PIN650VA', '', '', '', '', '', '0'),
(90, 78, 'chandu', 'Chandu Lamani', 'SAC', '', 'IBM', '', '4 Port(Extender)', 'PIN650VA', '', '', '', '', 'Extension Board(1)', '0'),
(91, 60, 'computercenter', 'Suresh. Ramaswamy', 'CSA', 'CSA-Office', 'IBM', '7912', '4 Port', '', '', '', '', 'HP LJ 3020', '', '0'),
(92, 60, 'computercenter', 'Suresh. Ramaswamy', 'CSA', 'CSA-Office', 'DELL-360', '', '', '', '', '', '', '', '', '0'),
(93, 108, 'pmsingru', 'Pravin M. Singru', 'MEC', 'Mech. Offi', 'HP, IBM, DELL-755', '7912', '', '', '', '', '', 'HP LJ 3020, HP PS C4488', 'D-Link 8 Port Switch', '0'),
(94, 108, 'pmsingru', 'Pravin M. Singru', 'MEC', 'Workshop O', 'HP(2 No''s), WIPRO', '7912(4 No''s)', '', '', '', '', '', 'HP LJ M1120 MFP', '', '0'),
(95, 104, 'ratabole', 'Raghunath A. Ratabole', 'WILP', 'WILP Offic', '', '7912(3 No''s)', '', '', '', '', 'HP Elite Book 2730P', '', '2 Mice & 2 Keyboards', '0');

-- --------------------------------------------------------

--
-- Table structure for table `groupleader`
--

CREATE TABLE `groupleader` (
  `id` int(3) NOT NULL auto_increment,
  `PSRN` int(3) NOT NULL,
  `LOGINID` varchar(20) NOT NULL,
  `NAME` char(40) NOT NULL,
  `DEPARTMENT` char(20) NOT NULL,
  `LOCATION` varchar(10) NOT NULL,
  `COMPUTER` char(20) NOT NULL,
  `IP_PHONE` varchar(30) NOT NULL,
  `CPE` varchar(30) NOT NULL,
  `UPS` varchar(30) NOT NULL,
  `HEADPHONE` varchar(20) NOT NULL,
  `WEBCAM` varchar(20) NOT NULL,
  `LAPTOP` varchar(30) NOT NULL,
  `PRINTER` varchar(30) NOT NULL,
  `OTHERS` varchar(20) NOT NULL,
  `FLAG` char(2) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=138 ;

--
-- Dumping data for table `groupleader`
--

INSERT INTO `groupleader` (`id`, `PSRN`, `LOGINID`, `NAME`, `DEPARTMENT`, `LOCATION`, `COMPUTER`, `IP_PHONE`, `CPE`, `UPS`, `HEADPHONE`, `WEBCAM`, `LAPTOP`, `PRINTER`, `OTHERS`, `FLAG`) VALUES
(1, 26, 'computercenter', 'Utpal Roy', 'BIO', 'Genetic  E', '', '7912', '', '', '', '', '', '', '', '0'),
(2, 26, 'computercenter', 'Utpal Roy', 'BIO', 'Micro Bio ', '', '7912', '', '', '', '', '', '', '', '0'),
(3, 26, 'computercenter', 'Utpal Roy', 'BIO', 'Bio MT-1 L', '', '7912', '', '', '', '', '', 'HP LJ 3020', '', '0'),
(4, 26, 'computercenter', 'Utpal Roy', 'BIO', 'Bio Inform', 'IBM', '7912', '', 'NUM600VA', '', '', '', '', '', '0'),
(5, 26, 'computercenter', 'Utpal Roy', 'BIO', 'Biotech La', '', '7912', '', '', '', '', '', '', '', '0'),
(6, 26, 'computercenter', 'Utpal Roy', 'BIO', 'Bio Resear', 'IBM', '7912', '', '', '', '', '', '', '', '0'),
(7, 26, 'computercenter', 'Utpal Roy', 'BIO', ' Bio Prote', 'IBM(2 No''s)', '', '', 'NUM600VA(2 No''s)', '', '', '', '', '', '0'),
(8, 68, 'dmk', 'Srinivas Krishnaswamy', 'CHE', 'Process Co', ' HP(12 No''s)', '7912', '', '', '', '', '', '', '', '0'),
(9, 68, 'dmk', 'Srinivas Krishnaswamy', 'CHE', 'Mass Trans', ' HP(3 No''s), IBM', '7912', '', '', '', '', '', '', '', '0'),
(10, 68, 'dmk', 'Srinivas Krishnaswamy', 'CHE', 'Material S', '', '7912', '', '', '', '', '', '', '', '0'),
(11, 68, 'dmk', 'Srinivas Krishnaswamy', 'CHE', 'Chemical A', 'HP', '7912', '', '', '', '', '', '', '', '0'),
(12, 68, 'dmk', 'Srinivas Krishnaswamy', 'CHE', 'SCEO Lab', '', '7912', '', '', '', '', '', '', '', '0'),
(13, 68, 'dmk', 'Srinivas Krishnaswamy', 'CHE', 'MT-2 Chemi', ' HP (1) & IBM (1)', '7912', '', '', '', '', '', 'HP LJ 3020', '', '0'),
(14, 95, 'sunilbhand', 'Sunil Bhand', 'CHY', 'MT-1 Chemi', 'IBM', '7912', '', 'NUM600VA', '', '', '', '', '', '0'),
(15, 95, 'sunilbhand', 'Sunil Bhand', 'CHY', 'Chemistry ', 'IBM', '7912', '', '', '', '', '', '', '', '0'),
(16, 95, 'sunilbhand', 'Sunil Bhand', 'CHY', 'Chemistry ', '', '7912', '', '', '', '', '', 'HP LJ 3020', '', '0'),
(17, 95, 'sunilbhand', 'Sunil Bhand', 'CHY', 'Chemistry ', 'IBM(2 No''s)', '7912', '', '', '', '', '', '', '', '0'),
(18, 95, 'sunilbhand', 'Sunil Bhand', 'CHY', 'IMA Lab', 'HP', '7912', '', '', '', '', '', 'HP LJ 3050', ' Spikeguard', '0'),
(19, 95, 'sunilbhand', 'Sunil Bhand', 'CHY', '', '', '7912', '', '', '', '', '', '', '', '0'),
(20, 299, 'anupkr', 'K.R. Anupama', 'EEE', 'Analog Dig', 'HP', '7912', '', '', '', '', '', '', '', '0'),
(21, 299, 'anupkr', 'K.R. Anupama', 'EEE', 'Digital Co', ' HP(4 No''s),IBM(A)', '7912', '', '', '', '', '', '', '', '0'),
(22, 299, 'anupkr', 'K.R. Anupama', 'EEE', 'EEE Simula', ' HP(12 No''s),IBM(4No', '7912', '4 Port', '', '', '', '', '', ' D-Link 8 port switc', '0'),
(23, 299, 'anupkr', 'K.R. Anupama', 'EEE', 'Elct / Ins', 'IBM(5 No''s),  IBM (3', '7912', '', '', '', '', '', '', '', '0'),
(24, 299, 'anupkr', 'K.R. Anupama', 'EEE', 'Elect Mach', 'WIPRO', '7912', '', '', '', '', '', 'HP LJ 3020', '', '0'),
(25, 299, 'anupkr', 'K.R. Anupama', 'EEE', 'EMB-LAB', ' HP(15 No''s)', '7912', '', '', '', '', '', 'HP LJ 1022n', '', '0'),
(26, 299, 'anupkr', 'K.R. Anupama', 'EEE', 'MicroElect', 'DELL-360(10 No''s)', '7912', '', '', '', '', '', '', '', '0'),
(27, 299, 'anupkr', 'K.R. Anupama', 'EEE', 'SERVER ROO', 'SUNSOLAR SERVER', '', '', '', '', '', '', '', '', '0'),
(28, 367, 'mraman', 'Meenakshi Raman', 'HMT', 'Language L', 'DELL-755(22 No''s), D', '7912', '', '', 'Digital Headphone (3', '', '', '', 'Computer Aided Lang.', '0'),
(29, 367, 'mraman', 'Meenakshi Raman', 'HMT', 'HUM', 'IBM', '', '', '', '', '', '', 'HP LJ 3020', '', '0'),
(30, 368, 'mraman', 'Meenakshi Raman', 'HMT', 'PhD Schola', 'IBM', '', '', '', '', '', '', '', '', '0'),
(31, 108, 'pmsingru', 'Pravin M. Singru', 'MEC', 'Robotic La', ' HP(2 No''s)', '7912', '', '', '', '', '', '', '', '0'),
(32, 108, 'pmsingru', 'Pravin M. Singru', 'MEC', 'Fluid Mech', '', '7912', '', '', '', '', '', '', '', '0'),
(33, 108, 'pmsingru', 'Pravin M. Singru', 'MEC', 'Thermal Sc', 'HP', '7912', '', '', '', '', '', '', '', '0'),
(34, 108, 'pmsingru', 'Pravin M. Singru', 'MEC', 'CNC Lab', ' HP(7 No''s)&IBM(4No''', '7912', '', '', '', '', '', '', '', '0'),
(35, 108, 'pmsingru', 'Pravin M. Singru', 'MEC', 'IC Engine ', 'WIPRO', '7912', '', 'PIN650VA', '', '', '', '', '', '0'),
(36, 108, 'pmsingru', 'Pravin M. Singru', 'MEC', 'MT-2 (mech', 'IBM', '7912', '', 'PIN650VA', '', '', '', '', '', '0'),
(37, 70, 'nandan', 'Patincharath Nandakumar', 'PHY', 'Physics Op', 'IBM(2 No''s)', '7912', '', 'NUM600VA', '', '', '', '', 'D-Link 8 port switch', '0'),
(38, 70, 'nandan', 'Patincharath Nandakumar', 'PHY', 'Physics So', '', '7912', '', '', '', '', '', '', '', '0'),
(39, 70, 'nandan', 'Patincharath Nandakumar', 'PHY', 'MT-1(Phisi', 'IBM, IBM, DELL VOSTR', '7912', '', '', '', '', '', 'HP LJ 3020', '', '0'),
(40, 70, 'nandan', 'Patincharath Nandakumar', 'PHY', 'SERVER ROO', 'DELL SERVER', '', '', '', '', '', '', '', '', '0'),
(41, 70, 'nandan', 'Patincharath Nandakumar', 'PHY', 'Project st', 'IBM(5 No''s)', '', '', 'NUM600VA(4 No''s)', '', '', '', '', '', '0'),
(42, 70, 'nandan', 'Patincharath Nandakumar', 'PHY', 'Ramshankar', 'IBM', '', '', '', '', '', '', '', '', '0'),
(43, 78, 'bmd', 'Bharat M. Deshpande', 'CSI', 'Central pr', 'IBM', '', '', '', '', '', '', 'HP LJ 3020', '', '0'),
(44, 78, 'bmd', 'Bharat M. Deshpande', 'CSI', 'A-412', 'IBM', '7912', '', '', '', '', '', '', '', '0');
