-- phpMyAdmin SQL Dump
-- version 3.2.0.1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Dec 29, 2012 at 10:14 AM
-- Server version: 5.1.36
-- PHP Version: 5.3.0
--
-- Create as table name "faculty" in database "icop"
--

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `icop`
--

-- --------------------------------------------------------

--
-- Table structure for table `faculty`
--
CREATE DATABASE `icop`
SELECT `icop`

CREATE TABLE IF NOT EXISTS `faculty` (
  `psrn` int(4) NOT NULL,
  `name` varchar(30) NOT NULL,
  `chamber` varchar(7) NOT NULL,
  PRIMARY KEY (`psrn`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Dumping data for table `faculty`
--

INSERT INTO `faculty` (`psrn`, `name`, `chamber`) VALUES
(2, 'Arun V. Kulkarni', 'C-209'),
(3, 'Aditya P. Koley', 'C-213'),
(4, 'Manjuri Kumar', 'A-3017'),
(6, 'D.M. Kulkarni', 'CC-201'),
(7, 'M.K. Deshmukh', 'B-403'),
(9, 'Anand K. Patil', 'B-301'),
(10, 'Neena Goveas', 'A-409'),
(11, 'Reeta S. Dubey', 'CC-204'),
(16, 'Raghu Nath Behera', 'C-221'),
(17, 'Tincy L.thomas', 'C-313'),
(21, 'Vikas V. Chaudhari', 'CC-210'),
(23, 'Basavadatta Mitra', 'A-312'),
(25, 'Sachin Waigaonkar', 'A-3138'),
(26, 'Utpal Roy', 'C-203'),
(28, 'Abhishek Kumar', 'A-31311'),
(33, 'Meenal Kowshik', 'C-204'),
(35, 'R.P. Pradhan', 'B-204'),
(39, 'C. Phaneendra Kiran', 'A-3137'),
(50, 'Anuradha Voolapalli', ''),
(52, 'Judith Maria Braganca', 'C-205'),
(56, 'Varinder Singh', 'A-3132'),
(58, 'Narendra Nath Ghosh', 'C-208'),
(60, 'Suresh Ramaswamy', 'B-402'),
(62, 'Radhika Vathsan', 'CC-111'),
(64, 'Anita B. Agrawal', 'A-404'),
(66, 'P.Venkateswara Rao', 'A-3012'),
(68, 'Srinivas Krishnaswamy', 'A-3011'),
(69, 'Lucy J. Gudino', 'A-414'),
(70, 'Patincharath Nandakumar', 'CC-207'),
(71, 'Debasis Patnaik', 'A-302'),
(72, 'V.V.S.N.V. Prasad', 'A-311'),
(73, 'P.N.Deepak', 'CC-112'),
(77, 'Prasanna Kumar N.', 'CC-203'),
(78, 'Bharat M. Deshpande', 'A-408'),
(80, 'M. Srikanth', 'C-201'),
(81, 'Raghvendra G.S. ', 'A-402'),
(82, 'Veeky Baths', 'CC-216'),
(83, 'J.V. Rao', 'A-410'),
(84, 'Mangesh Bedekar', 'CC-107'),
(85, 'Anjan Chattopadhyay', 'C-219'),
(89, 'Gaurav Dhar', 'C-217'),
(92, 'Anant C. Kulkarni', 'A-3133'),
(93, 'Tarkeshwar Singh', 'CC-215'),
(94, 'Sutapa Roy Ramanan', 'A-3014'),
(95, 'Sunil Bhand', 'C-211'),
(96, 'K.V.R.B. Prasad', 'A-424'),
(102, 'Pinky P Pawaskar', 'CC-217'),
(104, 'Raghunath A. Rathabole', 'CC-114'),
(107, 'A. Amalin Prince', 'A-2062'),
(108, 'Pravin M. Singru', 'A-3136'),
(111, 'Nitin Upadhyay', 'A-421'),
(112, 'Shalini Upadhyay', 'A-306'),
(113, 'Aruna Bomma Reddi', 'A-309'),
(114, 'Sanjay Kumar Sahay', 'A-407'),
(116, 'Anasuya Ganguly', 'C-202'),
(119, 'Jyotsna A. Kulkarni', 'A-4012'),
(120, 'Toby Joseph', 'CC-218'),
(121, 'P. Dhanumjaya', 'CC-209'),
(122, 'Ranjan Dey', 'A-3016'),
(123, 'Reena Cheruvalath', 'CC-206'),
(124, 'Sunil Kumar V.', 'CC-115'),
(126, 'Rabi Narayan Panda', 'B-312'),
(172, 'Vaishnavi T. Unde', 'A-3013'),
(180, 'Shibu Clement', 'A-31312'),
(184, 'Anil Kumar', 'CC-205'),
(185, 'Sampatrao Dagu Manjare', 'A-3019'),
(189, 'Rashmi Chauhan', 'C-315'),
(192, 'Ramprasad S. Joshi', 'A-405'),
(193, 'Kuttalaprakash C.', 'B-111'),
(197, 'C. Balakrishna Moorthy', 'A-422'),
(199, 'Dilip Kumar Mohanty', 'A-3135'),
(207, 'Mitaxi P. Mehta', 'CC-105'),
(210, 'Nitin Sharma', 'A-2063'),
(211, 'P.Bhavana ', 'C-223'),
(212, 'Naik Raghvendra Datta', 'A-30118'),
(226, 'Gautam G. Bacher', 'A-426'),
(228, 'Mali Kiran Dinkar', 'A-31310'),
(229, 'Chhayadevi M. Bhamare', 'A-4013'),
(230, 'Raghvendra K.M.', ''),
(232, 'Jessica Pereira', 'CC-116'),
(237, 'Prasanta Kumar Das', 'B-314'),
(246, 'Manisha Dixit', 'CC-106'),
(292, 'Meghanand A. Bhamare', 'A-4011'),
(296, 'Aruna Govada', 'A-406'),
(297, 'Saby John K.', 'B-409'),
(298, 'K. P. Jayadevan', 'B-309'),
(299, 'K.R. Anupama', 'A-4015'),
(302, 'K.E. Raman', 'B-406'),
(305, 'Vaishali Sharma', 'CC-208'),
(309, 'Sujit Kumar Ghosh', 'C-220'),
(310, 'Saroj S. Baral', 'A-3015'),
(311, 'Surendran G.', 'A-30111'),
(317, 'M Shreedhar Babu', 'A-3139'),
(318, 'Halan Prakash', 'CC-101'),
(323, 'Rajendra Kumar Roul', 'A-30112'),
(327, 'N Kubendran', 'A-303'),
(328, 'Mridula Goel', 'B-201'),
(329, 'P.L.Ramkumar', 'A-3134'),
(332, 'Ambili K', 'A-308'),
(333, 'Ramesha C. K', 'A-4016'),
(334, 'Pravin Mane', 'A-4014'),
(337, 'K. Chandram', 'A-4017'),
(338, 'Aswini KUmar Mishra', 'B-310'),
(340, 'K.V.Santhilata', 'A-420'),
(343, 'Amit Setia', 'A-30121'),
(346, 'Dibakar CHakrabarty', 'B-215'),
(348, 'Teny Theresa John', 'B-105'),
(362, 'Chandradew Sharma', 'C-319'),
(363, 'Mainak Banerjee', 'C-207'),
(364, 'Amrita Chatterjee', 'C-222'),
(356, 'Mahadev Gawas', 'A-403'),
(367, 'Meenakshi Raman', 'B-303'),
(369, 'Sheron Figarado', 'A-2061'),
(370, 'Vineet Kumar Singh', 'A-30115'),
(371, 'K.R. Biju', 'A-413'),
(372, 'Manoj Kumar Pandey', 'A-30114'),
(373, 'Bijil Prakash', 'A-30113'),
(375, 'Vinita George', 'A-415'),
(376, 'Sarang C Dhongdi', 'A-419'),
(377, 'Ram Shanker Patel', 'C-214'),
(381, 'Vijayashree Nayak ', 'B-210'),
(383, 'G. Gyanesh', 'A-310'),
(410, 'Tarun Kumar Jha', 'B-106'),
(412, 'Sumit Biswas', 'C-212'),
(414, 'Angshuman Sarkar', 'B-308'),
(416, 'Jajati Keshari Sahoo', 'CC-214'),
(418, 'Gautum Krishnan', 'B-316'),
(420, 'K.A. Geetha ', 'A-30120'),
(425, 'Shikha Sahai', 'B-203'),
(430, 'R Femi', 'A-415'),
(431, 'Amol Deshpande', 'A-30110'),
(432, 'Narayan Suresh Manjarekar', 'A-2065'),
(433, 'Krishnaswamy N. Ponnani', 'A-3018'),
(434, 'Muslim', 'CC-213'),
(435, 'Mnadar Ashok Gupte', 'A-419'),
(436, 'Shubhagi K. Gawali', 'A-418'),
(437, 'B.J.C. Babu', 'C-210'),
(452, 'Hemanta Kumar', 'A-3131'),
(454, 'Sangeeta Jaiswal', 'CC-103'),
(456, 'Geeta Patil', 'A-411'),
(457, 'Sreejith V', 'A-416');
