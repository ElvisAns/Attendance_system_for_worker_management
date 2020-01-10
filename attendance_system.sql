-- phpMyAdmin SQL Dump
-- version 4.1.14
-- http://www.phpmyadmin.net
--
-- Host: 127.0.0.1
-- Generation Time: May 06, 2018 at 01:01 PM
-- Server version: 5.6.17
-- PHP Version: 5.5.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `attendance_system`
--

-- --------------------------------------------------------

--
-- Table structure for table `id_tag_record`
--

CREATE TABLE IF NOT EXISTS `id_tag_record` (
  `id` bigint(20) DEFAULT NULL,
  `Roll_Number` varchar(30) DEFAULT NULL,
  `Names` varchar(30) DEFAULT NULL,
  `identification_info` varchar(20) DEFAULT NULL,
  UNIQUE KEY `id` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Dumping data for table `id_tag_record`
--

INSERT INTO `id_tag_record` (`id`, `Roll_Number`, `Names`, `identification_info`) VALUES
(83523405870, '201710122', 'FUNDIKO LUCIEN', 'Y2/CS/E'),
(83523409901, '201710402', 'MARCELO TUNASS', 'Y2/CS/E'),
(83523775870, '201750122', 'KENAYA_LUNE MASIKA', 'Y3/COT/D'),
(83923405202, '201710234', 'EVODIE LUKEKA', 'Y1/EBS/D'),
(83923405232, '201650334', 'JUSTIN MASIMANGO', 'Y2/ETT/D'),
(83923405245, '201510100', 'ANABELLA MUNAMAME', 'Y3/EBS/A/D'),
(83923405265, '201650201', 'ALICIA KAREKE', 'Y1/ETT/D'),
(83923405499, '201750233', 'ELVIS KANYABO', 'Y1/CS/E');

-- --------------------------------------------------------

--
-- Table structure for table `logs`
--

CREATE TABLE IF NOT EXISTS `logs` (
  `id` int(6) unsigned NOT NULL AUTO_INCREMENT,
  `Roll_Number` varchar(30) DEFAULT NULL,
  `Names` varchar(30) DEFAULT NULL,
  `Profiles` varchar(20) DEFAULT NULL,
  `Date` date DEFAULT NULL,
  `Time` time DEFAULT NULL,
  `TimeStamp` timestamp NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`),
  UNIQUE KEY `Roll_Number` (`Roll_Number`,`Names`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=5 ;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
