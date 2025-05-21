Create database PrisonDB;

Use PrisonDB;

Create Table Prison (
    prisonerID int auto_increment not null,
    lastName varchar(25),
    firstName varchar(25),
    photo varchar(999),
    birthDate date,
    height decimal,
    hair varchar(15),
    eyes varchar(15),
    placeOfBirth varchar(15),
    sentence varchar(255),
    dateOfConviction date,
    dateToBeLiberated date,
    unique(prisonerID)
);   

insert into Prison
values (null, 'Manson', 'Charles', 'cmanson.jpg', '1934-11-12', 5.7, 'black', 'black', 'USA', 
        'Commuted to life imprisonment without the possibility of parole', '1951-10-01', null); 
        
Select * from Prison;

