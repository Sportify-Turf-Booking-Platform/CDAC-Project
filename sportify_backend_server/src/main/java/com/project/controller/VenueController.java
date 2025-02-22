package com.project.controller;

import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

import org.modelmapper.ModelMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import com.project.custom_exception.ApiException;
import com.project.dto.BookingSummaryDTO;
import com.project.dto.CourtResponseDTO;
import com.project.dto.PlayerBookingResponse;
import com.project.dto.PlayerBookingSummaryDTO;
import com.project.dto.SportResponseDTO;
import com.project.dto.VenueResponseDTO;
import com.project.pojos.Booking;
import com.project.pojos.Venue;
import com.project.repository.BookingRepository;
import com.project.repository.CourtRepository;
import com.project.repository.VenueRepository;
import com.project.service.BookingService;
import com.project.service.VenueService;

@RestController
@RequestMapping("/venue")
public class VenueController {

	@Autowired
	private VenueService venueService;

	@Autowired
	private BookingService bookingService;

	@Autowired
	private VenueRepository venueRepository;

	@Autowired
	private ModelMapper modelMapper;

	@Autowired
	private BookingRepository bookingRepository;

	@Autowired
	private CourtRepository courtRepository;

	@GetMapping("/search")
	public ResponseEntity<List<VenueResponseDTO>> getVenues(@RequestParam(required = false) String locality,
			@RequestParam(required = false) String sportName, @RequestParam(defaultValue = "false") boolean available) {
		return ResponseEntity.ok(venueService.getVenues(locality, sportName, available));
	}

	@GetMapping("/all")
	public ResponseEntity<List<VenueResponseDTO>> getAllVenues() {
		List<VenueResponseDTO> venues = venueService.getAllVenues();
		return ResponseEntity.ok(venues);
	}

	@GetMapping("/search/{locality}")
	public ResponseEntity<List<VenueResponseDTO>> getVenuesFromLocality(
			@PathVariable(required = false) String locality) {
		return ResponseEntity.ok(venueService.getVenuesFromLocality(locality));

	}

	@GetMapping("/{venueId}/courts")
	public ResponseEntity<List<CourtResponseDTO>> getCourtsByVenue(@PathVariable Long venueId) {
		List<CourtResponseDTO> response = venueService.getCourtsByVenue(venueId);
		return ResponseEntity.ok(response);
	}

	@GetMapping("/sports")
	public ResponseEntity<List<SportResponseDTO>> getAllSports() {
		List<SportResponseDTO> response = venueService.getAllSports();
		return ResponseEntity.ok(response);
	}

	@GetMapping("/owner/{ownerId}")
	public ResponseEntity<List<VenueResponseDTO>> getVenuesByOwner(@PathVariable Long ownerId) {
		return ResponseEntity.ok(venueService.getVenuesByOwner(ownerId));
	}

	@GetMapping("/owner/{ownerId}/courts")
	public ResponseEntity<List<CourtResponseDTO>> getCourtsByOwner(@PathVariable Long ownerId) {
		List<CourtResponseDTO> response = venueService.getCourtsByOwner(ownerId);
		return ResponseEntity.ok(response);
	}

	@GetMapping("/{venueId}/bookings/summary")
	public ResponseEntity<List<BookingSummaryDTO>> getBookingSummaries(@PathVariable Long venueId) {
		Venue venue = venueRepository.findById(venueId).orElseThrow(() -> new ApiException("Venue not found"));

		// Get all bookings associated with the venue
		List<Booking> bookings = bookingRepository.findByCourtVenue(venue);

		// Convert Booking entities to BookingSummaryDTO
		List<BookingSummaryDTO> summaries = bookings.stream().map(BookingSummaryDTO::new).collect(Collectors.toList());

		return ResponseEntity.ok(summaries);
	}

	@GetMapping("/owner/bookings")
	public ResponseEntity<List<PlayerBookingSummaryDTO>> getPlayerBookingsForOwner(@RequestParam Long facilityOwnerId) {

		List<Venue> venues = venueRepository.findByFacilityOwnerId(facilityOwnerId);

		List<Booking> bookings = bookingRepository.findByCourt_VenueIn(venues);

		List<PlayerBookingSummaryDTO> bookingSummaries = bookings.stream().map(PlayerBookingSummaryDTO::new)
				.collect(Collectors.toList());

		return ResponseEntity.ok(bookingSummaries);
	}

	@GetMapping("/{venueId}")
	public ResponseEntity<Map<String, String>> getVenueDetails(@PathVariable Long venueId) {
		Map<String, String> venue = venueService.getVenueDetails(venueId);
		return ResponseEntity.ok(venue);
	}

	@GetMapping("/courts/{courtId}")
	public ResponseEntity<CourtResponseDTO> getCourtById(@PathVariable Long courtId) {
		CourtResponseDTO courtResponse = venueService.getCourtById(courtId);
		return ResponseEntity.ok(courtResponse);
	}

	@GetMapping("/search/venue/{sport}")
	public ResponseEntity<List<VenueResponseDTO>> getVenuesBySport(@PathVariable String sport) {
		List<VenueResponseDTO> venues = venueService.getVenuesBySport(sport);
		if (venues.isEmpty()) {
			return ResponseEntity.noContent().build();
		}
		return ResponseEntity.ok(venues);
	}

	@GetMapping("/total/{facilityOwnerId}")
	public ResponseEntity<Long> getTotalBookings(@PathVariable Long facilityOwnerId) {
		Long totalBookings = bookingService.getTotalBookingsByFacilityOwner(facilityOwnerId);
		return ResponseEntity.ok(totalBookings);
	}

	@GetMapping("/players/{facilityOwnerId}")
	public ResponseEntity<List<PlayerBookingResponse>> getPlayersByFacilityOwnerId(@PathVariable Long facilityOwnerId) {
		List<PlayerBookingResponse> players = bookingService.getPlayersByFacilityOwnerId(facilityOwnerId);
		return ResponseEntity.ok(players);
	}

}
